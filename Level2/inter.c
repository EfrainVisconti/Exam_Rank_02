// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <unistd.h>

void	printlst(int *lst)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		if (lst[i] == 0)
			return ;
		write(1,&lst[i],1);
		i++;
	}
}

void	addinlist(int c, int *lst)
{
	int i;

	i = 0;
	while (i < 256)
	{
		if (lst[i] == 0)
		{
			lst[i] = c;
			return ;
		}
		i++;
	}
}

int	isinlst(int c, int *lst)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		if (lst[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int lst[256];

	i = 0;
	while (i < 256)
	{
		lst[i] = 0;
		i++;
	}
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			j = 0;
			while (argv[2][j] != '\0')
			{
				if (argv[1][i] == argv[2][j] && isinlst(argv[1][i], lst) == 0)
					addinlist(argv[1][i], lst);
				j++;
			}
			i++;
		}
	}
	printlst(lst);
	write(1,"\n",1);
	return (0);
}

