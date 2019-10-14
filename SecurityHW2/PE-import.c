#include <stdio.h>
#include <string.h>

char hideLetter(char c) {
	return c + 0x50;
}

char* unhideString(char string[]) {
	do { char * pointer = string ; while (*pointer) *pointer++ -= 0x50; } while(0);
	return string;
}

char* hideString(char string[]) {
	do {char * pointer = string ; while (*pointer) *pointer++ += 0x50;} while(0);
	return string;
}


int main( int argc, const char* argv[] )
{
	FILE *filePointer;
	filePointer = fopen("PE-1.txt", "w");
	
    char str[] = { hideLetter('I') , hideLetter(' ') , hideLetter('w') , hideLetter('a') , hideLetter('n'), hideLetter('t') , 
			mhideLetter(' ') , hideLetter('t') , hideLetter('o') , hideLetter(' '),
            hideLetter('l') ,hideLetter('e') ,hideLetter('a') ,hideLetter('r') ,hideLetter('n') ,hideLetter(' '),
			hideLetter('P') ,hideLetter('E') ,hideLetter(' ') ,hideLetter('f') ,hideLetter('i') ,hideLetter('l') ,hideLetter('e') ,
			hideLetter(' ') ,hideLetter('f') ,hideLetter('o') ,hideLetter('r') ,hideLetter('m') ,hideLetter('a') ,hideLetter('t') ,
			hideLetter('!'), '\0' }; 

	
	fprintf(filePointer, unhideString(str));
	hideString(str); 
	fclose(filePointer);
}


