#include "common.h"
#include "debug.h"
#include "chunk.h"

int main(int argc, char const *argv[]) {
    Chunk chunk;

    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);
    writeChunk(&chunk, OP_RETURN);
    writeChunk(&chunk, OP_RETURN);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);

    return 0;
}
