CC = gcc
FLAGS = -Werror -std=c23

all: slotto

slotto:
	$(CC) $(FLAGS) src/main.c -o builds/slotto.exe
	./builds/slotto.exe
