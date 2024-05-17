// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}

char    *ft_strrev(char *str)
{
	int	i;
	int	end;
	char	tmp;

	i = 0;
	end = ft_strlen(str) - 1;
	if (str == 0)
		return (0);
	while (i < end)
	{
		tmp = str[i];
		str[i] = str[end];
		str[end] = tmp;
		end--;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("%s\n", argv[1]);
// 		printf("%s\n", ft_strrev(argv[1]));
// 	}
// }