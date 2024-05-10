// Assignment name  : first_word
// Expected files   : first_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its first word, followed by a
// newline.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or if there are no words, simply display
// a newline.

// Examples:

// $> ./first_word "FOR PONY" | cat -e
// FOR$
// $> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
// this$
// $> ./first_word "   " | cat -e
// $
// $> ./first_word "a" "b" | cat -e
// $
// $> ./first_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

#include <unistd.h>

void	putchar_aux(char c)
{
		write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	char *s1 = argv[1];

	i = 0;
	if (argc == 1 || argc > 2)
		write(1,"\n", 1);

	else if (argc == 2)
	{
		while (s1[i])
		{
			if (s1[i] != 32)
				putchar_aux(s1[i]);
			else 
				return (0);
			i++;
		}
	}
	return (0);
}
