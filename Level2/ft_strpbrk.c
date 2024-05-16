// Assignment name	: ft_strpbrk
// Expected files	: ft_strpbrk.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strpbrk
// (man strpbrk).

// The function should be prototyped as follows:

// char	*ft_strpbrk(const char *s1, const char *s2);

#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (s2)
	{
		while (s1)
		{
			if (*s1 == *s2)
				return ((char *)s1);
			s1++;
		}
		s2++;
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("%s\n", argv[1]);
// 		printf("%s\n", ft_strpbrk(argv[1], argv[2]));
// 	}
// }