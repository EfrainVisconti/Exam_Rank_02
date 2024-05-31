// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);

#include <stdlib.h>

int	count_words(char *s)
{
	int	i = 0;
	int words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && (s[i+1] == '\0' || s[i+1] == '\n' || s[i+1] == '\t' || s[i+1] == ' '))
			words++;
		i++;
	}
	return (words);
}

char    **ft_split(char *str)
{
	int	row = 0;
	int col;
	int	j;
	int	i = 0;
	char	**array;

	array = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (array == 0)
		return (0);
	while (str[i] != '\0')
	{
		col = 0;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		j = i;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		array[row] = (char *)malloc(sizeof(char) * (i - j + 1));
		if (array[row] == 0)
			return (0);
		while (j < i)
		{
			array[row][col] = str[j];
			j++;
			col++;
		}
		array[row][col] = '\0';
		row++;
	}
	array[row] = 0;
	return (array);
}
