#include "common.h"
#include "debug.h"
#include "chunk.h"

int main(int argc, char const *argv[]) {
    Chunk chunk;

    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);

    int constant = addConstant(&chunk, 123);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);

    disassembleChunk(&chunk, "test chunk #1");


    writeChunk(&chunk, OP_RETURN);

    constant = addConstant(&chunk, 256);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);

    disassembleChunk(&chunk, "test chunk #2");

    for (int i = 0; i < chunk.count; i++) {
        printf("%d ", chunk.code[i]);
    }

    freeChunk(&chunk);

    return 0;
}
