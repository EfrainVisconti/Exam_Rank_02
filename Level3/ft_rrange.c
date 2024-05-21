// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

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
	if (end > start)
	{
		while (i < size)
		{
			array[i] = end;
			i++;
			end--;
		}
	}
	else if (end < start)
	{
		while (i < size)
		{
			array[i] = end;
			i++;
			end++;
		}
	}
	else
		array[i] = start;
	return (array);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	*tab;
// 	int	idx;
// 	int	start;
// 	int	end;
// 	int	size;

// 	idx = 0;
// 	start = 5;
// 	end = -5;
// 	tab = ft_range(start, end);
// 	size = get_size(start, end);
// 	printf("%i\n", size);
// 	while (idx < size)
// 	{
// 		printf("%i ", tab[idx]);
// 		idx++;
// 	}
// 	printf("\n");
// }