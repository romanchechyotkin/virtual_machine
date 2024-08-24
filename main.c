#include "common.h"
#include "debug.h"
#include "chunk.h"

int main(int argc, char const *argv[]) {
    Chunk chunk;

    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN, 1);

    int constant = addConstant(&chunk, 123);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

    disassembleChunk(&chunk, "test chunk #1");

    writeChunk(&chunk, OP_RETURN, 2);

    constant = addConstant(&chunk, 256);
    writeChunk(&chunk, OP_CONSTANT, 2);
    writeChunk(&chunk, constant, 2);

    disassembleChunk(&chunk, "test chunk #2");

    freeChunk(&chunk);

    return 0;
}
