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
	./src/widgets/Battery.cpp \
	./src/widgets/Hours.cpp \
	./src/widgets/RootSymol.cpp \
	./src/widgets/Path.cpp \
	./src/widgets/Minute.cpp \
	./src/widgets/Seconds.cpp \
	./src/widgets/User.cpp \
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
	./src/commands/init.cpp

OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:.cpp=.o)

CFLAGS   = -O2 -Wall -Wextra -Werror -pedantic -march=native -I./src
CXXFLAGS = -O2 -Wall -Wextra -Werror -pedantic -march=native -std=c++20 -I./src
LDFLAGS  = -static
NAME = prompter

CC = clang++


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(NAME)

re: clean all

.PHONY: all clean re
