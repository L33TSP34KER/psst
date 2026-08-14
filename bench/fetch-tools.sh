#!/usr/bin/env bash
# Fetch the exact external tools used by the comparison.
set -euo pipefail
cd "$(dirname "$0")"

STARSHIP_VERSION="1.26.0"
mkdir -p tools
curl -fsSL --max-time 120 \
    -o /tmp/starship-psst.tar.gz \
    "https://github.com/starship/starship/releases/download/v${STARSHIP_VERSION}/starship-x86_64-unknown-linux-musl.tar.gz"
tar -xzf /tmp/starship-psst.tar.gz -C tools starship
rm -f /tmp/starship-psst.tar.gz
curl -fsSL --max-time 30 \
    -o tools/flamegraph.pl \
    https://raw.githubusercontent.com/brendangregg/FlameGraph/master/flamegraph.pl
chmod +x tools/starship tools/flamegraph.pl

tools/starship --version | head -1
echo "benchmark tools ready"
