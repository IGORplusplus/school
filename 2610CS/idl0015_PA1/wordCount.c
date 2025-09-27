#include <stdio.h>
#include <stdbool.h>

/* I should not have used a macro here lol */
#define isVowel(x) ((x == 'a') || ( x == 'e') || (x == 'i') || (x == 'o') || (x == 'u') || (x == 'A') || (x == 'E') || (x == 'I') || (x == 'O') || (x == 'U'))
#define isSeparator(x) ((x == ' ') || ( x == '.') || (x == '?') || (x == ';') || (x == ',') || (x == ':'))

int main(int argc, char *argv[]) {

    printf("Input in your sentence to be analyzed\n");
    char sentence[256];

    if(fgets(sentence, sizeof(sentence), stdin) != NULL){
	printf("%s\n", sentence);
    } else {
	perror("ERROR reading the sentence");
    }

/*     alpha bounds  */
    char alpha_lower = 'A';
    char alpha_upper = 'z';

/*     number bounds  */
    char digit_lower = '0';
    char digit_upper = '9';

    char *it = sentence;

/*     this is for keeping track of if the pointer is in the middle of a word or not. */
    bool in_word = false;

    int char_count = 0;
    int word_count = 0;
    int alpha_count = 0;
    int digit_count = 0;
    int vowel_count = 0;

    while(*it != '\0') {
	if(( *it > alpha_lower ) && ( *it < alpha_upper)) {
	    alpha_count++;

	    if(isVowel(*it)){
		vowel_count++;
	    }
	    in_word = true;
	} else if(( *it >= digit_lower ) && ( *it <= digit_upper)) {
	    /* words don't have digits inside of them */
	    digit_count++;
	} else if( isSeparator(*it) ){
	    word_count++;
	    in_word = false;
	}
	char_count++;
	it++;
    }

    printf("Character count: %d\n", char_count);
    printf("Alpha count: %d\n", alpha_count);
    printf("Vowel count: %d\n", vowel_count);
    printf("Digit count: %d\n", digit_count);
    printf("Word count: %d\n", word_count);

    return 0;
}
