#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    printf("Please input two non-zero positive integers < 10\nThe first one being greater than the second\n");

    /*
    signs for these do not exist, so if -1 is entered, it will be interpreted as the max
    value that a 32 unsigned int can be which is in around 4 billion
    */

    uint32_t a, b;

    while(1) {
    scanf("%u", &a);
    scanf("%u", &b);
	if( (a > 10) || (a < 0)) {
	    printf("Atleast A wasn't valid\n");
	    printf("Try again\n");
	    continue;
	}
	if( (b > 10) || (b < 0)){
	    printf("B wasn't valid\n");
	    printf("Try again\n");
	    continue;
	}
	if( !(b < a) ) {
	    printf("B: %u, must be < A: %u\n", a, b);
	    printf("Try again\n\n");
	    continue;
	}
	break;
    }

    printf("Valid\n");
    printf("A: %u \nB: %u\n", a, b);

/*
 *  I split up a and b to find the result more easily
 *
 *  I am adding the a part by having a temp number that keeps track of the previous
 *  added a^# power so that I can add it to the total a_part_result
*/
    uint32_t a_part_result = 0;
    uint32_t previous = a;

    for(int n=1; n <= a; n++){
	a_part_result += (previous);
	previous *= a;
    }


    uint32_t b_part_result = a * b;
    uint32_t result = a_part_result - b_part_result;

    printf("result: %u\n", result);
    return 0;
}
