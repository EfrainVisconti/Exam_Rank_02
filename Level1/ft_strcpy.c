// Assignment name  : ft_strcpy
// Expected files   : ft_strcpy.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcpy (man strcpy).

// Your function must be declared as follows:

// char    *ft_strcpy(char *s1, char *s2);

char	*ft_strcpy(char	*s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	src[15] = "Hola Mundo!";
// 	char	dst[15] = "";

// 	printf("%s", src);
// 	printf("\n");
// 	printf("%s", dst);
// 	printf("\n");
// 	ft_strcpy(dst, src);
// 	printf("%s", dst);
// 	return (0);
// }