#include "sort.h"
/**
 * swap_ints - Swaps two integers in an array and prints the array
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * @array: The array containing the integers
 * @size: Number of elements in @array
 */
void swap_ints(int *a, int *b, int *array, size_t size)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}
/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme
 *
 * @array: The array to be partitioned
 * @low: The starting index
 * @high: The ending index
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
				swap_ints(&array[i], &array[j], array, size);
		}
	}

	if ((i + 1) != high)
		swap_ints(&array[i + 1], &array[high], array, size);

	return (i + 1);
}
/**
 * quick_sort_recursive - Recursively sorts the array using Quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index
 * @high: The ending index
 * @size: Number of elements in @array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}
