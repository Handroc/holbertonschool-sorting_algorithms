#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, yasi;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		yasi = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[yasi])
				yasi = j;
		}
		if (yasi != i)
		{
			temp = array[i];
			array[i] = array[yasi];
			array[yasi] = temp;
		}
		print_array(array, size);
	}
}
