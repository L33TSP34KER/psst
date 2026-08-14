#!/usr/bin/env python3
"""Convert callgrind output to folded stacks for flamegraph.pl.

Weight of each stack line = exclusive Ir (instructions retired) attributable
to that exact call path: arc inclusive cost minus child arc costs.
Sum of all lines ~= total Ir (reported on stderr for sanity checking).

Usage: callgrind2folded.py callgrind.out.NNN > out.folded
"""
import re
import sys


def parse(path):
    fn_name = {}          # fn id -> name
    self_cost = {}        # fn id -> self Ir
    arcs = {}             # (caller id, callee id) -> inclusive Ir of that arc
    events_idx = 0        # column index of Ir in cost lines
    cur_fn = None
    pending_arc = None    # callee id waiting for its arc cost line

    idref = re.compile(r"^\((\d+)\)\s*(.*)$")

    def resolve(tok, table):
        m = idref.match(tok)
        if m:
            fid = int(m.group(1))
            if m.group(2):
                table[fid] = m.group(2)
            return fid
        # uncompressed name: use the name itself as key
        table[tok] = tok
        return tok

    with open(path) as f:
        for line in f:
            line = line.rstrip("\n")
            if not line or line.startswith("#"):
                continue
            if line.startswith("events:"):
                events_idx = line.split()[1:].index("Ir")
                continue
            if line.startswith(("fl=", "ob=", "cfl=", "cob=")):
                continue
            if line.startswith("fn="):
                cur_fn = resolve(line[3:], fn_name)
                self_cost.setdefault(cur_fn, 0)
                pending_arc = None
                continue
            if line.startswith("cfn="):
                pending_arc = resolve(line[4:], fn_name)
                continue
            if line.startswith("calls="):
                continue
            if line[0].isdigit() or line[0] in "*+-":
                parts = line.split()
                if len(parts) < 2:
                    continue
                cost = int(parts[1 + events_idx])
                if pending_arc is not None:
                    arcs[(cur_fn, pending_arc)] = \
                        arcs.get((cur_fn, pending_arc), 0) + cost
                    pending_arc = None
                elif cur_fn is not None:
                    self_cost[cur_fn] = self_cost.get(cur_fn, 0) + cost
                continue
    return fn_name, self_cost, arcs


def emit_folded(fn_name, self_cost, arcs, out):
    children = {}
    has_parent = set()
    for (caller, callee), cost in arcs.items():
        children.setdefault(caller, []).append((callee, cost))
        has_parent.add(callee)

    roots = [f for f in self_cost if f not in has_parent] or list(self_cost)
    emitted = 0
    # stack of (path list, node, inclusive cost along this path)
    stack = [([fn_name.get(r, str(r))], r, self_cost[r]
              + sum(c for _, c in children.get(r, []))) for r in roots]
    while stack:
        path, node, incl = stack.pop()
        kids = [(c, w) for c, w in children.get(node, [])
                if fn_name.get(c, str(c)) not in path]  # guard recursion
        excl = incl - sum(w for _, w in kids)
        if excl > 0:
            out.write(f"{' ;'.join(path)} {excl}\n")
            emitted += excl
        for callee, w in kids:
            stack.append((path + [fn_name.get(callee, str(callee))], callee, w))
    return emitted


def main():
    fn_name, self_cost, arcs = parse(sys.argv[1])
    total_self = sum(self_cost.values())
    emitted = emit_folded(fn_name, self_cost, arcs, sys.stdout)
    print(f"total Ir (self): {total_self}", file=sys.stderr)
    print(f"total emitted:   {emitted} ({100*emitted/max(total_self,1):.1f}%)",
          file=sys.stderr)


if __name__ == "__main__":
    main()
