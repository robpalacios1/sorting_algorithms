#include "sort.h"

/**
 *
 *
 *
 *
 */

int quick_partition(int *array, int low, int high, size_t size)
{
	int p = array[high];
	int i = (low - 1);
	int j, temp = 0;

	for (j = low; j < high - 1; j++)
	{
		if (array[j] < p)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[j] != array[i])
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (array[j] != array[i])
		print_array(array, size);
	temp = i +1;
	return (temp);
}


void re_quick(int *array, int low, int high, size_t size)
{
	size_t pi = 0;

	if (low < high)
	{
		pi = quick_partition(array, low, high, size);

		re_quick(array, low, pi - 1, size);
		re_quick(array, pi + 1, high, size);
	}
}

/**
 *
 *
 *
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size <2)
		return;

	re_quick(array, 0, size - 1, size);
}
