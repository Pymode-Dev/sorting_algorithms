#include "sort.h"

/**
 * get_max - the maximum value in an array
 * @array: An array of int
 * @size: the size of the array
 * Return: int
 */

int get_max(int *array, int size)
{
	int m, i;

	for (m = array[0], i = 1; i < size; i++)
	{
		if (array[i] > m)
				m = array[i];
	}
	return (m);
}

/**
 * counting_sort - sorts an array using counting sort algo
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *sort, m, i;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);

	if (sort == NULL)
		return;

	m = get_max(array, size);
	counter = malloc(sizeof(int) * (m + 1));

	if (counter == NULL)
	{
		free(sort);
		return;
	}

	for (i = 0; i < (m + 1); i++)
	{
		counter[i] = 0;
	}


	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;

	for (i = 0; i < (m + 1); i++)
		counter[i] += counter[i - 1];

	print_array(counter, m + 1);

	for (i = 0; i < (int)size; i++)
	{
		sort[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];


	free(sort);
	free(counter);
}

