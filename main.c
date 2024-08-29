#include "debug.h"
#include "chunk.h"
#include "vm.h"

int main(int argc, char const *argv[]) {
    initVM();

    Chunk chunk;

    initChunk(&chunk);

    writeConstant(&chunk, 123, 123);
    writeChunk(&chunk, OP_NEGATE, 123);
    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk #1");
    printInterpretResult(interpret(&chunk));
    
    freeChunk(&chunk);

    writeConstant(&chunk, 123, 123);
    writeChunk(&chunk, OP_INC, 123);
    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk #2");
    printInterpretResult(interpret(&chunk));

    freeChunk(&chunk);

    writeConstant(&chunk, 123, 123);
    writeChunk(&chunk, OP_DEC, 123);
    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk #3");
    printInterpretResult(interpret(&chunk));

    freeVM();
    freeChunk(&chunk);

    return 0;
}

/*
1) Our encoding of line information is hilariously wasteful of memory. Given that a series of instructions often correspond to the same source line, a natural solution is something akin to run-length encoding of the line numbers. 
Devise an encoding that compresses the line information for a series of instructions on the same line. 
Change writeChunk() to write this compressed form, and implement a getLine() function that, given the index of an instruction, determines the line where the instruction occurs. 
Hint: It’s not necessary for getLine() to be particularly efficient. Since it is called only when a runtime error occurs, it is well off the critical path where performance matters.

3) Our reallocate() function relies on the C standard library for dynamic memory allocation and freeing. malloc() and free() aren’t magic. 
Find a couple of open source implementations of them and explain how they work. 
How do they keep track of which bytes are allocated and which are free? 
What is required to allocate a block of memory? Free it? 
How do they make that efficient? 
What do they do about fragmentation?
Hardcore mode: Implement reallocate() without calling realloc(), malloc(), or free(). 
You are allowed to call malloc() once, at the beginning of the interpreter’s execution, to allocate a single big block of memory, which your reallocate() function has access to. 
It parcels out blobs of memory from that single region, your own personal heap. It’s your job to define how it does that.
*/