#include "sort.h"


/**
 * swap_arr - this swap element in an array
 * @array: the array
 * @first: the first element
 * @second: the second element
 * Return: None
 */

void swap_arr(int *array, size_t first, size_t second)
{
	size_t i, j;

	i = array[first];
	j = array[second];

	array[first] = j;
	array[second] = i;
}
