C_COMPILER = gcc
C_FLAGS = -Werror -std=c23

CPP_COMPILER = g++
CPP_FLAGS = -Werror -std=c++23

all: c_slotto cxx_slotto

gen_dirs:
	mkdir builds/ src/ includes/

c_slotto:
	$(C_COMPILER) $(C_FLAGS) src/main.c -o builds/c_slotto.exe
	./builds/c_slotto.exe

cpp_slotto:
	$(CPP_COMPILER) $(CPP_FLAGS) src/main.cpp -o builds/cpp_slotto.exe
	./builds/cpp_slotto.exe

.PHONY: clean
clean: 
	rm builds/*.exe