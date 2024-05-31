// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string as a parameter, and prints its words in
// reverse order.

// A "word" is a part of the string bounded by spaces and/or tabs, or the
// begin/end of the string.

// If the number of parameters is different from 1, the program will display
// '\n'.

// In the parameters that are going to be tested, there won't be any "additional"
// spaces (meaning that there won't be additionnal spaces at the beginning or at
// the end of the string, and words will always be separated by exactly one space).

// Examples:

// $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
// ironic? it Isn't gatherings. love I But people! hate You$
// $>./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "Wingardium Leviosa" | cat -e
// Leviosa Wingardium$
// $> ./rev_wstr | cat -e
// $
// $>

#include <unistd.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i; //start
	char	*s;
	int	j = 0; //end
	int aux;

	if (argc == 2)
	{
		s = argv[1];
		i = ft_strlen(s) - 1;

		while (i >= 0)
		{
			while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
				i--;
			j = i;
			while (i >= 0 && s[i] != ' ' && s[i] != '\t')
				i--;
			aux = i + 1;
			while (aux <= j)
			{
				write(1,&s[aux],1);
				aux++;
			}
			if (i != -1)
				write(1," ",1);
		}
	}
	write(1,"\n",1);
	return (0);
}
