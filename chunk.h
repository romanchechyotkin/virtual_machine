#ifndef uman_chunk_h
#define uman_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OP_CODE;

typedef struct chunk {
    int count;
    int capacity;
    uint8_t* code;
    ValueArray constants;
} Chunk; 

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t opcode);
int addConstant(Chunk* chunk, Value value);
void freeChunk(Chunk* chunk);

#endif