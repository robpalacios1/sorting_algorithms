#include "sort.h"

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
	if (flag)
	{
	swap(&array[i +1], &array[high]);
	print_array(array, p);
	}
	return (i + 1);
}


void re_quick(int *array, int low, int high, size_t size)
{
	int pi = 0;

	if (low < high)
	{
		int pi = partition(array, low, high);

		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
	}
}
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;

	re_quick(array, 0, size -1, size);
}
