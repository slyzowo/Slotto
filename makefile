CC = gcc
FLAGS = -Werror -std=c23

all: slotto

slotto:
	$(CC) $(FLAGS) src/main.c include/terminal_colors.a -o builds/slotto.exe
	./builds/slotto.exe