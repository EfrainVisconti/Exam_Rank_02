// Assignment name  : expand_str
// Expected files   : expand_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it with exactly three spaces
// between each word, with no spaces or tabs either at the beginning or the end,
// followed by a newline.

// A word is a section of string delimited either by spaces/tabs, or by the
// start/end of the string.

// If the number of parameters is not 1, or if there are no words, simply display
// a newline.

// Examples:

// $> ./expand_str "See? It's easy to print the same thing" | cat -e
// See?   It's   easy   to   print   the   same   thing$
// $> ./expand_str " this        time it      will     be    more complex  " | cat -e
// this   time   it   will   be   more   complex$
// $> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
// $
// $> ./expand_str "" | cat -e
// $
// $>

 #include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	char	*s;

	if (argc == 2)
	{
		s = argv[1];
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		while (s[i] != '\0')
		{
			if (s[i] != ' ' && s[i] != '\t')
				write(1,&s[i],1);
			else if ((s[i] == ' ' || s[i] == '\t') && (s[i+1] >= 33 && s[i+1] <= 126))
				write(1,"   ",3);
			i++;
		}
	}
	write(1,"\n",1);
	return (0);
}
