// Assignment name  : rot_13
// Expected files   : rot_13.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the letter 13 spaces ahead in alphabetical order.

// 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

// The output will be followed by a newline.

// If the number of arguments is not 1, the program displays a newline.

// Example:

// $>./rot_13 "abc"
// nop
// $>./rot_13 "My horse is Amazing." | cat -e
// Zl ubefr vf Nznmvat.$
// $>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
// NxwuM mYXVWm , 23l $
// $>./rot_13 | cat -e
// $
// $>
// $>./rot_13 "" | cat -e
// $
// $>

#include <unistd.h>

void	rot13(char c, int n)
{
	char	new;

	if (n == 1)
		new = c + 13;
	if (n == 2)
		new = c + - 13;
	write(1,&new,1);
}



int	main(int argc, char **argv)
{
	int	i;
	char	*s;

	i = 0;
	if (argc == 2)
	{
		s = argv[1];
		while (s[i] != '\0')
		{
			if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
			{
				rot13(s[i], 1);
			}
			else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
			{
				rot13(s[i], 2);
			}
			else
				write(1,&s[i],1);
			i++;
		}
	}
	write(1,"\n",1);
	return (0);
}
