# Contributing to psst

psst is deliberately small. The best way to contribute is a widget, a bug fix,
or documentation that stays in the spirit of the project: minimal, fast, and
without runtime dependencies.

## Setup

Requirements: a C++20 compiler, GNU Make. `ccache` is optional but recommended;
the Makefile uses it when available.

```sh
make          # build ./prompter
make test     # run the widget tests
```

Test from both a repository directory and a non-repository directory before
opening a PR.

## Adding a widget

1. Implement `IWidget::render()` in a new header + source pair under
   `src/widgets/` (see `src/widgets/IWidget.hpp` and e.g. `Battery`).
2. Add the new source file to the `Makefile`.
3. Build and test as described above, from a repository and a non-repository
   directory.
4. If the widget affects prompt latency, run the benchmark harness in
   `bench/` and include the environment details in the PR description.

Widgets run on every prompt redraw, so keep them cheap: prefer direct file
reads and system calls over launching subprocesses.

## Style and rules

- Match the style of the existing files. No new runtime dependencies in the
  hot path.
- Document behavior that depends on platform files such as
  `/sys/class/power_supply` or `/proc/uptime`.
- Keep PRs small: one widget (or one logical fix) per PR.
- Update the widget table in `README.md` when you add a widget.

## Issues

Issues labeled `good first issue` are a good starting point. Ask questions in
the issue before starting a large change.
