#include "sort.h"

void swap_ar(int *a, int *b);

/**
 * swap_ar - swap two elements in an arrray
 * @a: first int
 * @b: second int
 * Return: void
 */

void swap_ar(int *a, int *b)
{
	int temp;

	temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * shell_sort - sorts an array of int using shell sort and Knuth algo
 * @array: the array to sort
 * @size: the size of an array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = (gap * 3) + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ar(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
