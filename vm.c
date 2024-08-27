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
            case OP_CONSTANT || OP_CONSTANT_LONG: {
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
        printf("INTERPRET_OK\n");
        break;
    case INTERPRET_COMPILE_ERROR:
        printf("INTERPRET_COMPILE_ERROR\n");
        break;
    case INTERPRET_RUNTIME_ERROR:
        printf("INTERPRET_RUNTIME_ERROR\n");
        break;
    }
}