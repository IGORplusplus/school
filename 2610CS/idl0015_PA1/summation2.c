#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    printf("Please input two non-zero positive integers < 20\n\n");

    /*
    signs for these do not exist, so if -1 is entered, it will be interpreted as the max
    value that a 64 unsigned int can be which is insanely high
    */

    uint64_t a, b;

    while(1) {
    scanf("%lu", &a);
    scanf("%lu", &b);
	if( (a > 20) || (a < 0)) {
	    printf("Atleast A wasn't valid\n");
	    printf("Try again\n");
	    continue;
	}
	if( (b > 20) || (b < 0)){
	    printf("B wasn't valid\n");
	    printf("Try again\n");
	    continue;
	}
	break;
    }

    printf("Valid\n");
    printf("A: %lu \nB: %lu\n", a, b);

/*
 *  I split up a and b to find the result more easily
 *
 *  I am adding the a part by having a temp number that keeps track of the previous
 *  added a^# power so that I can add it to the total a_part_result
*/
    uint64_t a_part_result = 0;
    uint64_t b_part_result = 0;
    uint64_t temp = 1;
    uint64_t temp_multiplier = 1;

    for(int n=1; n <= a; n++){
	a_part_result += temp;
	temp_multiplier++;
	temp *= (temp_multiplier);

	b_part_result += b;
    }

    uint64_t result = a_part_result + b_part_result;

    printf("result: %lu\n", result);
    return 0;
}
