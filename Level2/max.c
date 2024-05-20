// Assignment name  : max
// Expected files   : max.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// int		max(int* tab, unsigned int len);

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.

int	max(int	*tab, unsigned int len)
{
	unsigned int	i;
	int max;

	i = 0;
	max = 0;
	if (tab == 0)
		return (0);
	if (len > 0)
	{
		max = tab[i];
		while (i < len)
		{
			if (max < tab[i])
				max = tab[i];
			i++;
		}
	}
	return (max);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	res;
// 	int	tab[6] = {10, 10, 10, 10, 0, 10};

// 	res = max(tab, 6);
// 	printf("%i\n", res);
// 	return (0);
// }
