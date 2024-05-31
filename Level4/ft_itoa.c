// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

int	nlen(int nbr)
{
	int	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int	len;

	len = nlen(nbr);
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	len--;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
	{
		result[0] = "0";
		return (result);
	}
	while (nbr)
	{
		result[len] = (nbr % 10) + '0';
		len--;
		nbr = nbr / 10;
	}
	return (result);
}
