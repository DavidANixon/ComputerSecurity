#include <stdio.h>

int main (int argc, const char* argv[])
{
	int array[] = {0, 0, 0, 100};
	int eax = 0;
	int edx = 0;
	
	// 
	while (array[3] <= 999)
	{
		// index 2
		eax =  array[3]/100;
		array[2] = eax;
		
		// index 1
		edx = eax * -100;
		eax = array[3];
		eax = edx + eax;
		eax = eax/10;
		
		array[1] = eax;
		
		// index 0
		edx = array[3]/10 ;
		eax = edx * 4;
		eax += edx;
		eax += eax;
		
		array[0] = array[3] - eax;
		
		// Cubing and comparing
		eax = array[2] * array[2] * array[2];
		edx = eax;

		eax = array[1] * array[1] * array[1];
		edx += eax;

		eax = array[0] * array[0] * array[0];
		edx += eax;
		
		eax = edx;

		// if the sum of the first 3 elements cubed equals the counter
		if (eax == array[3])
		{
			printf("%d\n", array[3]);
		}
		array[3]++;
	}
}
