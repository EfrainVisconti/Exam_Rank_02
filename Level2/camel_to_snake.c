// Assignment name  : camel_to_snake
// Expected files   : camel_to_snake.c
// Allowed functions: malloc, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in lowerCamelCase format
// and converts it into a string in snake_case format.

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

// A snake_case string is a string where each word is in lower case, separated by
// an underscore "_".

// Examples:
// $>./camel_to_snake "hereIsACamelCaseWord"
// here_is_a_camel_case_word
// $>./camel_to_snake "helloWorld" | cat -e
// hello_world$
// $>./camel_to_snake | cat -e
// $

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1,&s[i],1);
		i++;
	}	
}

void	camel_to_snake(char	*src, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (src[i] >= 'A' && src[i] <= 'Z')
		{
				dst[j] = '_';
				dst[j + 1] = src[i] + 32;
				j++;
		}
		else
			dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
}

int	main(int argc, char **argv)
{
	char	*s;
	char	*d;

	if (argc == 2)
	{
		s = argv[1];
		d = (char *)malloc((ft_strlen(s) * 2) + 1);
		camel_to_snake(s, d);
		ft_putstr(d);
	}
	write(1,"\n",1);
	return (0);
}
