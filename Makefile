.PHONY: build
build:
	gcc -o ./bin/vm main.c memory.c chunk.c debug.c value.c vm.c

run: build
	bin/vm