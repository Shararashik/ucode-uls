.PHONY: all uls clean uninstall reinstall

all: uls clean

uls:
	@make -sC libmx
	@mkdir -p obj
	@cd obj ; clang -std=c11 -Wall -Wextra -Werror -Wpedantic ../src/*.c -c
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic -I inc/*.h libmx/libmx.a src/*.c -lmx -o uls
	@make uninstall -sC libmx

uninstall: clean
	@rm -rf uls

clean:
	@make clean -C libmx
	@rm -rf inc/@*.gch
	@rm -rf obj

reinstall: uninstall all



