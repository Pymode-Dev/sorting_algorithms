#include "sort.h"


/**
 * swap_arr - swap two elements in the array
 * @array: the array to manipulate
 * @first: the first element to manipulate
 * @second: the second element to manipulate
 * Return: void
 */

void swap_arr(int *array, size_t first, size_t second)
{
	size_t f, s;

	f = array[first];
	s = array[second];

	array[first] = s;
	array[second] = f;
}

/**
 * selection_sort - sorts an array of integers in ascending order using
 * selection sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, low;

	for  (i = 0; i < size; i++)
	{
		low = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[low])
				low = j;
		}
		if (low != i)
		{
			swap_arr(array, i, low);
			print_array(array, size);
		}
	}
}
