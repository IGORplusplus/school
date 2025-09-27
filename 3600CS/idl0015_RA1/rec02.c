#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int* int_ptr;
    int_ptr = malloc(2 * sizeof(int));
    if(int_ptr == NULL) {
	printf("Memory allocation failed!\n");
	return 1;
    }

    /* taking in the inputs */
    printf("Input first integer\n");
    scanf("%d", &int_ptr[0]);

    printf("Input second integer\n");
    scanf("%d", &int_ptr[1]);

    printf("First element: %d\nSecond element: %d\n", int_ptr[0], int_ptr[1]);

    /* swapping values without allocation of more memory*/
    printf("Swapping the first and second elements\n");
    int_ptr[0] = int_ptr[0] ^ int_ptr[1];

    int_ptr[1] = int_ptr[0] ^ int_ptr[1];

    int_ptr[0] = int_ptr[0] ^ int_ptr[1];

    printf("\nFirst element: %d\nSecond element: %d\n", int_ptr[0], int_ptr[1]);

    /* freeing memory */
    free(int_ptr);
    return 0;
}
