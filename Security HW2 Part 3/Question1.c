#include <stdio.h>

int main (int argc, const char* argv[])
{
	int input[] = {0, 5, 3};
	
	int multiply = input[2] * input[1];
	
	int divide = input[2]/2;
	divide = input[2] + divide;
	divide = divide / 2;
	
	int result = multiply - divide;
	
	printf("%d", result);
}
