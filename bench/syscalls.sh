#!/usr/bin/env bash
# Syscall-level comparison via strace -c, plus starship's own module timings.
set -euo pipefail
cd "$(dirname "$0")"

PSST="$PWD/../prompter"
STARSHIP="$PWD/tools/starship"
DIRTY_DIR="$PWD/fixtures/dirty-repo"
export SHELL=/bin/bash
unset STARSHIP_CONFIG || true

strace -c -f -o results/strace-psst-repo.txt    "$PSST" init      > /dev/null
strace -c -f -o results/strace-starship-repo.txt "$STARSHIP" prompt > /dev/null

( cd "$DIRTY_DIR" \
    && strace -c -f -o "$OLDPWD/results/strace-psst-dirty.txt"    "$PSST" init      > /dev/null \
    && strace -c -f -o "$OLDPWD/results/strace-starship-dirty.txt" "$STARSHIP" prompt > /dev/null )

# starship is stripped, so user-space attribution comes from its own profiler.
"$STARSHIP" timings > results/starship-timings-repo.txt 2>&1 || true
( cd "$DIRTY_DIR" && "$STARSHIP" timings > "$OLDPWD/results/starship-timings-dirty.txt" 2>&1 || true )

echo "strace + timings results written to results/"
