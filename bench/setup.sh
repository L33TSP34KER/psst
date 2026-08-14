#!/usr/bin/env bash
# Recreate benchmark fixtures from scratch.
set -euo pipefail
cd "$(dirname "$0")/fixtures"

mkdir -p empty-dir

if [ ! -d dirty-repo/.git ]; then
    mkdir -p dirty-repo
    cd dirty-repo
    git init -q
    git -c user.email=bench@local -c user.name=bench commit -q --allow-empty -m init
    for i in $(seq 1 1000); do : > "untracked_$i.txt"; done
    mkdir -p sub
    for i in $(seq 1 50); do echo modified > "sub/file_$i.txt"; done
    cd ..
fi

echo "fixtures ready"
