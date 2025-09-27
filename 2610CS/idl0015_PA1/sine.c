#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

/*     sin(x^2) = summation from n=0 to a ( (-1)^n) * (x)^(4n + 2) / (2n + 1)! */

/*     inputs */
    float x = 0.0f;
    uint32_t a = 0;

    printf("Input in values for a single precision floating point x,\nand an unsigned integer a.\n");
/*     taking in inputs */
    scanf("%f", &x);
    scanf("%u", &a);

    printf("You inputted %f as x and %u as a\n", x, a);

   
    float result = 0.0f;
    float numerator_exp = x * x;
    uint64_t denom_factorial = 1;
    int sign = 1;
    int factorial_temp = 1;

    for(uint32_t n=0; n<=a; n++) {

/* 	ignore n = 0 */
	if( n > 0) {
	    factorial_temp += 2;
	    denom_factorial = 1;
	    for(int i = factorial_temp; i>0; i--) {
		denom_factorial *= i;
	    }
	}

	float temp = sign * ((numerator_exp) / denom_factorial);
	result += temp;

	numerator_exp = numerator_exp * x * x * x * x;

	/* time to flip the signs */
	sign *= -1;
    }

    printf("With the given values of x: %f and a: %u\nThe result was %f\n", x, a, result);
    return 0;
}
