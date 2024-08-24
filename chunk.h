#ifndef uman_chunk_h
#define uman_chunk_h

#include "common.h"

typedef enum {
    OP_RETURN,
} OP_CODE;

typedef struct chunk {
    int count;
    int capacity;
    uint8_t* code;
} Chunk; 

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t opcode);
void freeChunk(Chunk* chunk);

#endif