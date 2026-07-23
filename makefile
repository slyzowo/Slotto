C_COMPILER = gcc
C_FLAGS = -Werror -std=c23

all: c_slotto

gen_dirs:
	mkdir builds/ src/ includes/

c_slotto:
	$(C_COMPILER) $(C_FLAGS) src/main.c -o builds/c_slotto.exe
	./builds/c_slotto.exe

.PHONY: clean
clean: 
	rm builds/*.exe