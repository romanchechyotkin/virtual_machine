#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for 10 integers using malloc
    int* arr = (int*)malloc(10 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Use the memory, for example, initialize it
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }

    // Reallocate memory to hold 20 integers
    arr = (int*)realloc(arr, 20 * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Use the newly allocated memory
    for (int i = 10; i < 20; i++) {
        arr[i] = i * 2;
    }

    // Print the array
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory
    free(arr);
    
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}