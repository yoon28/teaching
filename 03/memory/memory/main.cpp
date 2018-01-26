#include <stdio.h>
void main()
{
	int arr[3];
	for (int i = 0; i < 3; ++i)
		arr[i] = i+1;
	
	printf("%d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3]);

	int arr2[3] = { 1 , 2, 3 };
	int arr3[] = { 1, 2 };
}