// Assignment name  : ulstr
// Expected files   : ulstr.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and reverses the case of all its letters.
// Other characters remain unchanged.

// You must display the result followed by a '\n'.

// If the number of arguments is not 1, the program displays '\n'.

// Examples :

// $>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
// l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
// $>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
// s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
// $>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
// 3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
// $>./ulstr | cat -e
// $

#include <unistd.h>

void	ulstr(char	c, int n)
{
	char	new;

	if (n == 1)
	{
		new = c - 32;
		write(1,&new,1);
	}
	else if (n == 2)
	{
		new = c + 32;
		write(1,&new,1);
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
				ulstr(s[i], 1);
			else if (s[i] >= 'A' && s[i] <= 'Z')
				ulstr(s[i], 2);
			else
				write(1,&s[i],1);
			i++;
		}
	}
	write(1,"\0",1);
	return (0);
}
