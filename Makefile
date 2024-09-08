.PHONY: build
build:
	mkdir -p bin
	gcc -o ./bin/vm main.c memory.c chunk.c debug.c value.c vm.c

run: build
	bin/vm