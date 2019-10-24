#include <stdio.h>

// This function returns the maximum element in the array
int main (int argc) 
{
	int array[] = {12, 15, 221, 3, 432, 54, 15, 67, 0, 0};
	int counter = array[9];
	while (array[9] <= 7) {
		counter = array[9];
		if (array[counter] > array[8]) {
			array[8] = array[counter];
		}
		array[9]++;
	}
	
	printf("%d", array[8]);
}
