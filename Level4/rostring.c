// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring "first" "2" "11000000"
// first
// $>
// $>./rostring | cat -e
// $
// $>

#include <unistd.h>

void	first_word(char *s)
{
	int	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while(s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
	{
		write(1,&s[i],1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i = 0;
	char	*s;

	if (argc >= 2)
	{
		s = argv[1];
		while (s[i] != 0 && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] != 0 && s[i] != ' ' && s[i] != '\t')
			i++;
		while (s[i] != 0)
		{
			if (s[i] != ' ' && s[i] != '\t')
			{
				write (1,&s[i],1);
				if (s[i+1] == ' ' || s[i+1] == '\t' || s[i+1] == '\0')
					write(1," ",1);
			}
			i++;
		}

		first_word(s);
	}
	write(1,"\n",1);
	return (0);
}