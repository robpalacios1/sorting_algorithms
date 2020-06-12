#include "sort.h"

/**
 *
 *
 *
 *
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_idx = 0, flag = 0;

	for (i = 0; i < size-1; i++)
	{
		flag = 0;
		min_idx = i;
		for (j = i+1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				flag = 1;
			}
		}
		if (flag)
		{
		swap(&array[min_idx], &array[i]);
		print_array(array, size);
		}
	}
}
