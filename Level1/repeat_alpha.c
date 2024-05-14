// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>

#include <unistd.h>

void	putchar_n(char c, int n)
{
	while (n >= 0)
	{
		write(1,&c,1);
		n--;
	}
}

int	main(int argc, char **argv)
{
	int		i = 0;
	char	*s;

	if (argc != 2 || argv[1][0] == '\0')
		write(1,"\n",1);
	else if (argc == 2)
	{
		s = argv[1];
		while (s[i] != '\0')
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				putchar_n(s[i], s[i] - 'a');
			}
			else if (s[i] >= 'A' && s[i] <= 'Z')
			{
			putchar_n(s[i], s[i] - 'A');
				}
			else
				write(1,&s[i],1);
			i++;
		}
		write(1,"\n",1);
	}
	return (0);
}
