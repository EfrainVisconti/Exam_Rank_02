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

void	print_list(int *lst)
{
	int i = 0;
	while (lst[i] != 0)
	{
		write(1,&lst[i],1);
		i++;
	}
}

void	add_list(int *lst, int c)
{
	int i = 0;
	while (lst[i] != 0)
		i++;
	lst[i] = c;
}

int	isinlist(int *lst, int c)
{
	int i = 0;
	while (lst[i] != 0)
	{
		if (lst[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	lst[256];
	char	*f;
	char	*s;

	if (argc == 3)
	{
		f = argv[1];
		s = argv[2];
		while (i < 256)
		{
			lst[i] = 0;
			i++;
		}
		i = 0;
		while (f[i] != '\0')
		{
			if (isinlist(lst, f[i]) == 0)
				add_list(lst, f[i]);
			i++;
		}
		i = 0;
		while (s[i] != '\0')
		{
			if (isinlist(lst, s[i]) == 0)
				add_list(lst, s[i]);
			i++;
		}
		print_list(lst);
	}
	write(1,"\n",1);
	return (0);
}
