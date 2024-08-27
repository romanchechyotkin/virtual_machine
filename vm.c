#include "vm.h"

VM vm;

void initVM() {}

void freeVM() {}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

    for (;;) {
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_RETURN: {
                return INTERPRET_OK;
            }
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                printValue(constant);
                printf("\n");
                break;
            }
        }
    }

#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult interpret(Chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}


void printInterpretResult(InterpretResult res) {
    switch (res) {
    case INTERPRET_OK:
        return printf("INTERPRET_OK\n");
    case INTERPRET_COMPILE_ERROR:
        return printf("INTERPRET_COMPILE_ERROR\n");
    case INTERPRET_RUNTIME_ERROR:
        return printf("INTERPRET_RUNTIME_ERROR\n");
    }
}