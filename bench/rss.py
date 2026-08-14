#!/usr/bin/env python3
"""Peak RSS comparison: run each prompt N times, take max child RSS."""
import os
import resource
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.join(HERE, "..")
RUNS = 300

TARGETS = {
    "psst": [os.path.join(REPO, "prompter"), "init"],
    "starship-default": [os.path.join(HERE, "tools", "starship"), "prompt"],
}

def peak_rss_kb(argv):
    env = dict(os.environ, SHELL="/bin/bash")
    for _ in range(RUNS):
        subprocess.run(argv, cwd=REPO, env=env,
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                       check=True)
    # max RSS over all reaped children so far
    return resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss

def main():
    rows = []
    for name, argv in TARGETS.items():
        rows.append((name, peak_rss_kb(argv)))
    out = os.path.join(HERE, "results", "rss.md")
    with open(out, "w") as f:
        f.write(f"Peak RSS over {RUNS} runs (ru_maxrss, KiB)\n\n")
        f.write("| tool | peak RSS (KiB) |\n|---|---|\n")
        for name, kb in rows:
            f.write(f"| {name} | {kb} |\n")
    print(f"wrote {out}")
    for name, kb in rows:
        print(f"  {name}: {kb} KiB")

if __name__ == "__main__":
    sys.exit(main())
