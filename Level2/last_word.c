// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	end;
	char	*s;

	if (argc == 2)
	{
		s = argv[1];
		end = ft_strlen(s) - 1;
		while (end >= 0)
		{
			if (s[end] == ' ' || s[end] == '\t')
				end--;
			else if (s[end] != ' ' && s[end] != '\t')
			{
				end--;
				if (s[end] == ' ' || s[end] == '\t')
					break;
			}
		}
		while (s[end + 1] != '\0')
		{
			if (s[end + 1] != ' ' && s[end + 1] != '\t')
				write(1,&s[end + 1],1);
			end++;
		}
	}
	write(1,"\n",1);
	return (0);
}