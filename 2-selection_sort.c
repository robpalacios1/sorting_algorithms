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
 * selection_sort - sorts an array by repeatedly finding the minimum element \
(considering ascending order) \
from unsorted part and putting it at the beginning
 * @array: Array to evaluated
 *
 * @size: size of Array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_idx = 0, flag = 0;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		min_idx = i;
		for (j = i + 1; j < size; j++)
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
