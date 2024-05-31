// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <stdlib.h>

int	get_size(int start, int end)
{
	int	size = 0;
	
	if (start < end)
	{
		while (start <= end)
		{
			size++;
			start++;
		}
	}
	else if (start > end)
	{
		while (start >= end)
		{
			size++;
			start--;
		}
	}
	else
		size = 1;
	return (size);
}

int     *ft_range(int start, int end)
{
	int	i = 0;
	int	size;
	int	*array;

	size = get_size(start, end);
	array = malloc(sizeof(int) * size);
	if (start > end)
	{
		while (i < size)
		{
			array[i] = start;
			i++;
			start--;
		}
	}
	else if (start < end)
	{
		while (i < size)
		{
			array[i] = start;
			i++;
			start++;
		}
	}
	else
		array[i] = start;
	return (array);
}
