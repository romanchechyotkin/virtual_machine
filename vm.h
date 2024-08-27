#ifndef uman_vm_h
#define uman_vm_h

#include "common.h"
#include "chunk.h"

typedef struct {
    Chunk* chunk;
} VM;


void initVM();
void freeVM();

#endif