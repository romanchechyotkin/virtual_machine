#include "vm.h"
#include "debug.h"

VM vm;

static void resetStack() {
    vm.stackTop = vm.stack;
}

void initVM() {
    resetStack();
}

void freeVM() {}

void push(Value value) {
    *vm.stackTop = value;
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--;
    return *vm.stackTop;
}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

    for (;;) {

#ifdef DEBUG_TRACE_EXECUTION
    printf("           ");
    for (Value* slot = vm.stack; slot < vm.stackTop; slot++) {
        printf("[ ");
        printValue(*slot);
        printf(" ]");
    }
    printf("\n");

    disassembleInstruction(vm.chunk, (int)(vm.ip-vm.chunk->code));
#endif

        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_RETURN: {
                printValue(pop());
                printf("\n");
                return INTERPRET_OK;
            }
            case OP_NEGATE:
                push(-pop());
                break;    
            case OP_INC:
                push(incValue(pop()));
                break;
            case OP_DEC:
                push(decValue(pop()));
                break;        
            case OP_CONSTANT ... OP_CONSTANT_LONG: {
                Value constant = READ_CONSTANT();
                push(constant);
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