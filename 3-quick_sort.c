#include "sort.h"

/**
 * swap - function to swapping values
 * @a: value one for swap
 *
 * @b: value two for swap
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}


/**
 * quick_partition - partition array between low and high index
 * @array: input array.
 * @low: index of start of array.
 * @high: index of end of array.
 * @size: length of array.
 * Return: Starting index plus one
 */

int quick_partition(int *array, int low, int high, size_t size)
{
	int p = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= p)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	if (i != j)
	{
		print_array(array, size);
	}
	return (i);
}


/**
 * re_quick - Quick Sort with extra parameter size
 * @array: input array.
 * @low: index of start of array
 * @high: index of end of array
 * @size: size length of array
 */

void re_quick(int *array, int low, int high, size_t size)
{

	if (low < high)
	{
		int pi = quick_partition(array, low, high, size);

		re_quick(array, low, pi - 1, size);
		re_quick(array, pi + 1, high, size);
	}
}


/**
 * quick_sort - function that sorts an array of integers in ascending \
 order using the Quick sort algorithm
 * @array: input array
 * @size: size length of array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	re_quick(array, 0, size - 1, size);
}
