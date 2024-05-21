// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <unistd.h>

void	printlist(int *lst)
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

int	isinlist(int c, int *lst)
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

int main(int argc, char **argv)
{
	int i;
	int lst[256] = {0};

	// i = 0;
	// while (i < 256)
	// {
	// 	lst[i] = 0;
	// 	i++;
	// }
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (isinlist(argv[1][i], lst) == 0)
				addinlist(argv[1][i], lst);	
			i++;
		}
		i = 0;
		while (argv[2][i] != '\0')
		{
			if (isinlist(argv[2][i], lst) == 0)
				addinlist(argv[2][i], lst);
			i++;
		}
		printlist(lst);
	}
	write(1,"\n",1);
	return (0);
}