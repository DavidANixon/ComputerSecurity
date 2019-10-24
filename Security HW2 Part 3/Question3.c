#include <stdio.h>

int main (int argc, const char* argv[])
{
	int array[] = {0, 0, 0,100};
	int eax = 0;
	int edx = 0;
	int ecx = 0;
	
	while (array[3] <= 999)
	{
		// index 2
		eax =  array[3]/100 - array[3]/2;
		array[2] = eax;
		
		// index 1
		edx = eax * -100;
		eax = array[3];
		ecx = edx + eax;
		edx = ecx / 5;
		eax = ecx / 2;
		edx -= eax;
		eax = edx;
		
		array[1] = eax;
		
		// index 0
		ecx = array[3];
		edx = ecx / 5;
		eax = ecx / 2;
		edx -= eax;
		eax = edx * 4;
		eax += edx;
		eax += eax;
		ecx -= eax;
		eax = ecx;
		
		array[0] = eax;
		
		// Cubing and comparing
		eax = array[2] * array[2] * array[2];
		edx = eax;
		eax = array[1] * array[1] * array[1];
		edx += eax;
		eax = array[0] * array[0] * array[0];
		edx += eax;
		
		eax = edx;
				
		if (eax == array[3])
		{
			printf("%d", array[3]);
		}
		array[3]++;
	}
}
