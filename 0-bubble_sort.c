#include "sort.h"


/**
 * swap_arr - This swap elements in an array
 *
 * @array: the array to manipulate
 * @first: the first element index to change
 * @second: the second element index to change
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
 * bubble_sort - function that sorts an array of integers in ascending order
 *
 * @array: the array to sort
 * @size: the size of the array to sort
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;


	i = 0;
	for (; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_arr(array, j, j + 1);
				print_array(array, size);
			}
		}
	}
}
