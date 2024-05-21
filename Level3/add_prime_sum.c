// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>

#include <unistd.h>

void	put_nbr(int	nbr)
{
	char	digit_char;

	if (nbr > 9)
	{
		put_nbr(nbr / 10);
		put_nbr(nbr % 10);
	}
	else
	{
		digit_char = nbr + '0';
		write(1, &digit_char, 1);
	}
}

int	atoi_pos(char *s)
{
	int	result;
	int	i = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}

int	is_prime(int nbr)
{
	int	check;

	check = 2;
	if (nbr <= 1)
		return (0);
	while (check < nbr)
	{
		if ((nbr % check) == 0)
			return (0);
		check++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	nbr;
	int result;

	if (argc == 2)
	{
		nbr = atoi_pos(argv[1]);
		result = 0;
		while (nbr > 0)
		{
			if (is_prime(nbr) == 1)
				result = result + nbr;
			nbr--;
		}
		put_nbr(result);
	}
	else
		write(1,"0",1);
	write(1,"\n",1);
	return (0);
}
