#!/usr/bin/env bash
# Reproduce every number in the README's Performance section.
# Requires: hyperfine, strace, valgrind, python3, taskset,
#           bench/tools/starship, bench/tools/flamegraph.pl
set -euo pipefail
cd "$(dirname "$0")"

./fetch-tools.sh
./setup.sh
./env.sh
./hyperfine.sh
./syscalls.sh
python3 rss.py
./flamegraph.sh

echo "all results in bench/results/"
