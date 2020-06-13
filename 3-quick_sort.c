#include <stdio.h>

/**
 *
 *
 *
 *
 */

int partition(int *array, int low, int high)
{
	int p = array[high];
	int i = (low - 1);
	int flag = 0;

	for (int j = low; j <= high - 1; j++)
	{
		flag = 0;
		if (array[j] < p)
		{
			i++;
			flag = 1;
			swap(&array[i], &array[high]);
		}
	}
	swap(&array[i +1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

void quick_sort(int *array, size_t size)
{
	size_t temp = 0;

	if (size < temp)
	{
		int p = partition(array, size, temp);

		quick_sort(array, size, p - 1);
		quick_sort(array, p + 1, size);
	}
}
