#!/usr/bin/env bash
# Instruction-count flamegraph of `prompter init` via valgrind/callgrind.
# Deterministic (no sampling noise), which suits a ~1ms binary.
#
# Starship's release binary is stripped, so an equivalent flamegraph would
# be all "???" frames; user-space attribution for starship comes from its
# built-in `starship timings` profiler instead (see syscalls.sh).
set -euo pipefail
cd "$(dirname "$0")/.."   # run inside the git repo, like a real prompt

export SHELL=/bin/bash
RES=bench/results

valgrind --tool=callgrind \
    --callgrind-out-file="$RES/callgrind.psst" \
    ./prompter init > /dev/null 2>"$RES/valgrind-psst.log"

python3 bench/callgrind2folded.py "$RES/callgrind.psst" > "$RES/psst.folded"

bench/tools/flamegraph.pl \
    --title "psst: prompter init (instruction counts, callgrind)" \
    --countname instructions \
    --width 1200 \
    "$RES/psst.folded" > "$RES/flamegraph-psst.svg"

echo "wrote $RES/flamegraph-psst.svg"
