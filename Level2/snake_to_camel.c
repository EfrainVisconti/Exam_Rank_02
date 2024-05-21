// Assignment name  : snake_to_camel
// Expected files   : snake_to_camel.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in snake_case format
// and converts it into a string in lowerCamelCase format.

// A snake_case string is a string where each word is in lower case, separated by
// an underscore "_".

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

// Examples:
// $>./camel_to_snake "here_is_a_snake_case_word"
// hereIsASnakeCaseWord
// $>./camel_to_snake "hello_world" | cat -e
// helloWorld$
// $>./camel_to_snake | cat -e
// $

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char	*s)
{
	int	i = 0;
	while (s[i] != '\0')
	{
		write(1,&s[i],1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	*s;
	char	*n;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		s = argv[1];
		n = malloc(ft_strlen(s) + 1);
		if (n == 0)
			return (0);
		while (s[i] != '\0')
		{
			if ((s[i] == '_') && s[i + 1] >= 'a' && s[i + 1] <= 'z')
			{
				n[j] = s[i + 1] - 32;
				i++;
				i++;
				j++;
			}
			else
			{
				n[j] = s[i];
				i++;
				j++;
			}
		}
		ft_putstr(n);
	}
	write(1,"\n",1);
	free(n);
	return (0);
}
