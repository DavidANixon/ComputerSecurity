#include <stdio.h>

int z5Proc(int *arrayPtr, int x, int y)
{
	// do something
	return 0;
}

int main (int argc)
{
	int arg1 = 100;
	int arg2 = 7;
	int counter = 0;
	int array[100];
	
	while (counter < arg1)
	{
		array[counter] = counter;
		counter++;
	}
	
	printf("%d", z5Proc(array, 100, 7));
	
}
