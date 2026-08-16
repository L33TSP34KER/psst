##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## project makefile
##

SRC = ./src/main.cpp \
	./src/shells/EShell.cpp \
	./src/shells/Fish.cpp \
	./src/shells/Bash.cpp \
	./src/parser.cpp \
	./src/widgets/ShortPath.cpp \
	./src/widgets/Battery.cpp \
	./src/widgets/Hours.cpp \
	./src/widgets/RootSymol.cpp \
	./src/widgets/GitBranch.cpp \
	./src/widgets/Path.cpp \
	./src/widgets/Minute.cpp \
	./src/widgets/Seconds.cpp \
	./src/widgets/User.cpp \
	./src/widgets/PythonVenv.cpp \
	./src/widgets/Hostname.cpp \
	./src/widgets/SSHSession.cpp \
	./src/widgets/ExitStatus.cpp \
	./src/widgets/NodeVersion.cpp \
	./src/widgets/Mem.cpp \
	./src/widgets/Container.cpp \
	./src/widgets/Tmux.cpp \
	./src/widgets/Charging.cpp \
	./src/widgets/Git.cpp \
	./src/widgets/Bat.cpp \
	./src/widgets/colors/Cyan.cpp \
	./src/widgets/colors/Bold.cpp \
	./src/widgets/colors/Blue.cpp \
	./src/widgets/colors/Reset.cpp \
	./src/widgets/colors/Purple.cpp \
	./src/widgets/colors/Yellow.cpp \
	./src/widgets/colors/Pink.cpp \
	./src/widgets/colors/Red.cpp \
	./src/widgets/colors/Green.cpp \
	./src/commands/init.cpp \
	./src/commands/help.cpp

OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:.cpp=.o)

CFLAGS   = -O3 -Wall -Wextra -Werror -pedantic -march=native -I./src
CXXFLAGS = -O3 -Wall -Wextra -Werror -pedantic -march=native -std=c++20 -I./src
LDFLAGS  = -static
NAME = prompter
PREFIX ?= $(HOME)/.local
BINDIR ?= $(PREFIX)/bin

CCACHE := $(shell command -v ccache 2>/dev/null)
ifneq ($(CCACHE),)
	CC  = ccache clang++
	CXX = ccache g++
else
	CC  = clang++
	CXX = g++
endif



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

re: clean all

install: $(NAME)
	@set -e; \
	install -Dm755 $(NAME) "$(BINDIR)/$(NAME)"; \
	shell="$${SHELL##*/}"; \
	case "$$shell" in \
		bash) \
			config="$(HOME)/.bashrc"; \
			mkdir -p "$$(dirname "$$config")"; \
			if ! grep -Fq 'prompter init' "$$config" 2>/dev/null; then \
				printf '%s\n' '' '# psst prompt' 'PROMPTER="$(BINDIR)/$(NAME)"' 'PROMPT_COMMAND='"'"'status_code=$$?; eval "$$($$PROMPTER init "$$status_code")"'"'" >> "$$config"; \
			fi; \
			;; \
		zsh) \
			config="$(HOME)/.zshrc"; \
			mkdir -p "$$(dirname "$$config")"; \
			if ! grep -Fq 'prompter init' "$$config" 2>/dev/null; then \
				printf '%s\n' '' '# psst prompt' 'PROMPTER="$(BINDIR)/$(NAME)"' 'precmd() { local status_code=$$?; eval "$$($$PROMPTER init "$$status_code")"; }' >> "$$config"; \
			fi; \
			;; \
		fish) \
			config="$(HOME)/.config/fish/config.fish"; \
			if ! grep -Fq 'prompter init' "$$config" 2>/dev/null; then \
				mkdir -p "$$(dirname "$$config")"; \
				printf '%s\n' '' '# psst prompt' 'function fish_prompt' '    set -l status_code $$status' '    $(BINDIR)/$(NAME) init $$status_code | source' 'end' >> "$$config"; \
			fi; \
			;; \
		esac

move: install
	@rm -f $(NAME)

.PHONY: all clean re install move

test: all
	./tests/run.sh

.PHONY: test
