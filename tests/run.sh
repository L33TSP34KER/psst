#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PROMPTER="$ROOT/prompter"

make -C "$ROOT" >/dev/null

test_bin="$(mktemp)"
trap 'rm -f "$test_bin"' EXIT

${CXX:-g++} -std=c++20 -Wall -Wextra -Werror -pedantic \
    -I"$ROOT/src" \
    "$ROOT/tests/widget_test.cpp" \
    "$ROOT/src/widgets/PythonVenv.cpp" \
    "$ROOT/src/widgets/Hostname.cpp" \
    "$ROOT/src/widgets/SSHSession.cpp" \
    "$ROOT/src/widgets/ExitStatus.cpp" \
    "$ROOT/src/widgets/NodeVersion.cpp" \
    "$ROOT/src/widgets/Mem.cpp" \
    "$ROOT/src/widgets/Container.cpp" \
    "$ROOT/src/widgets/Tmux.cpp" \
    -o "$test_bin"
"$test_bin"

echo "widget tests passed"
