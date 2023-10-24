#include "sort.h"


int lomuto_pivot(int *array, size_t size, int low, int high);
void lomuto_sort(int *array, size_t size, int low, int high);

/**
 * swap_arr - swaps two elements in an array
 * @array: the array to manipulate
 * @first: the first index to swap
 * @second: the second index to swap
 * Return: void
 */

void swap_arr(int *array, int first, int second)
{
	int f, s;

	f = array[first];
	s = array[second];

	array[first] = s;
	array[second] = f;
}

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}


/**
 * lomuto_pivot - pivot scheme using lomuto algorithm
 * @array: the array
 * @low: the lowest pivot
 * @high: the highest index
 * Return: size_t
 */

int lomuto_pivot(int *array, size_t size, int low, int high)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (pivot > array[j])
		{
			i++;
			swap_arr(array, i, j);
			print_array(array, size);
		}
	}
	swap_arr(array, i + 1, high);
	return (i + 1);
}

/**
 * lomuto_sort - lomuto sort using lomuto pivot scheme
 * @array: the array to sort
 * @low: the lowest pivot
 * @high: the highest pivot
 * Return: void
 */

void lomuto_sort(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = lomuto_pivot(array, size, low, high);

		lomuto_sort(array, size, low, p - 1);
		lomuto_sort(array, size, p + 1, high);
	}
}
