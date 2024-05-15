// Assignment name  : alpha_mirror
// Expected files   : alpha_mirror.c
// Allowed functions: write
// --------------------------------------------------------------------------------
 
// Write a program called alpha_mirror that takes a string and displays this string
// after replacing each alphabetical character by the opposite alphabetical
// character, followed by a newline.
 
// 'a' becomes 'z', 'Z' becomes 'A'
// 'd' becomes 'w', 'M' becomes 'N'
 
// and so on.
 
// Case is not changed.
 
// If the number of arguments is not 1, display only a newline.
 
// Examples:
 
// $>./alpha_mirror "abc"
// zyx
// $>./alpha_mirror "My horse is Amazing." | cat -e
// Nb slihv rh Znzarmt.$
// $>./alpha_mirror | cat -e
// $
// $>

#include <unistd.h>

void	alpha_mirror(char c, int n)
{
	char	aux;

	if (n == 1)
	{
		aux = 122 - c + 97;
		write(1,&aux,1);
	}
	else if (n == 2)
	{
		aux = 90 - c + 65;
		write(1,&aux,1);
	}
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
			if (s[i] >= 'a' && s[i] <= 'z')
				alpha_mirror(s[i], 1);
			else if (s[i] >= 'A' && s[i] <= 'Z')
				alpha_mirror(s[i], 2);
			else
				write(1,&s[i],1);
			i++;
		}
	}
	write(1,"\n",1);
	return (0);
}
