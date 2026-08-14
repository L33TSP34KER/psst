#!/usr/bin/env bash
# Dump benchmark environment details for the methodology section.
set -euo pipefail
cd "$(dirname "$0")"
RES=results/environment.txt

{
    echo "== date =="
    date -u
    echo
    echo "== uname =="
    uname -a
    echo
    echo "== cpu =="
    lscpu | grep -E 'Model name|^CPU\(s\)|CPU max|CPU min|L1d|L2|L3'
    echo
    echo "== governor =="
    cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor 2>/dev/null || echo "n/a"
    echo
    echo "== memory =="
    free -h | head -2
    echo
    echo "== tool versions =="
    hyperfine --version
    strace --version | head -1
    valgrind --version
    g++ --version | head -1
    tools/starship --version | head -1
    echo "prompter: $(git -C .. describe --always --dirty 2>/dev/null || echo unknown)"
    echo
    echo "== psst build flags =="
    grep -E '^(CFLAGS|CXXFLAGS|LDFLAGS)' ../Makefile
    echo
    echo "== binary sizes =="
    ls -l ../prompter tools/starship
    echo
    echo "== linkage =="
    file ../prompter tools/starship
} > "$RES" 2>&1

echo "wrote $RES"
