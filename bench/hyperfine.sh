#!/usr/bin/env bash
# Startup-time comparison: psst vs starship, via hyperfine.
# Two spawn modes per scenario:
#   sh    -> through /bin/sh -c (what a real shell does on every prompt)
#   none  -> direct exec (isolates the binary's own startup cost)
set -euo pipefail
cd "$(dirname "$0")"
ROOT="$PWD"

PSST="$PWD/../prompter"
STARSHIP="$PWD/tools/starship"
MINIMAL="$PWD/fixtures/starship-minimal.toml"
REPO_DIR="$PWD/.."
EMPTY_DIR="$PWD/fixtures/empty-dir"
DIRTY_DIR="$PWD/fixtures/dirty-repo"

RUNS=500
WARMUP=25
CPU=2   # pin to one core to reduce scheduler noise

run() {  # name, dir, extra-env (as a shell word, may be empty), commands...
    local name="$1" dir="$2"; shift 2
    local -a cmds=("$@")
    ( cd "$dir" && taskset -c "$CPU" hyperfine \
        --warmup "$WARMUP" --min-runs "$RUNS" \
        --export-markdown "$ROOT/results/hyperfine-${name}.md" \
        --export-json "$ROOT/results/hyperfine-${name}.json" \
        "${cmds[@]}" )
}

scenario() {  # tag, dir
    local tag="$1" dir="$2"
    export SHELL=/bin/bash

    unset STARSHIP_CONFIG || true
    run "${tag}-sh"   "$dir" \
        -n psst "$PSST init" \
        -n starship-default "$STARSHIP prompt"
    run "${tag}-none" "$dir" --shell=none \
        -n psst "$PSST init" \
        -n starship-default "$STARSHIP prompt"

    export STARSHIP_CONFIG="$MINIMAL"
    run "${tag}-minimal-sh"   "$dir" \
        -n starship-minimal "$STARSHIP prompt"
    run "${tag}-minimal-none" "$dir" --shell=none \
        -n starship-minimal "$STARSHIP prompt"
    unset STARSHIP_CONFIG
}

scenario repo   "$REPO_DIR"
scenario empty  "$EMPTY_DIR"
scenario dirty  "$DIRTY_DIR"

# Measurement floor: an absolute no-op through the same harness.
export SHELL=/bin/bash
run "floor-sh"   "$REPO_DIR" -n true "/bin/true"
run "floor-none" "$REPO_DIR" --shell=none -n true "/bin/true"

echo "hyperfine results written to results/"
