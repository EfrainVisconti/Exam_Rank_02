// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e
// 1$
// $> ./pgcd | cat -e
// $


#include <stdio.h>
#include <stdlib.h>

void	ft_pgcd(int nbr_1, int nbr_2)
{
	int	div;
	int	pgcd;

	div = 1;
	if (nbr_1 <= 0 || nbr_2 <= 0)
		return ;
	while ((div <= nbr_1) || div <= nbr_2)
	{
		if (((nbr_1 % div) == 0) && ((nbr_2 % div) == 0))
			pgcd = div;
		div++;
	}
	printf("%d", pgcd);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}