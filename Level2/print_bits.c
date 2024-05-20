// Assignment name  : print_bits
// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
// AT THE END.

// Your function must be declared as follows:

// void	print_bits(unsigned char octet);

// Example, if you pass 2 to print_bits, it will print "00000010"

#include <unistd.h> 
 void	print_bits(unsigned char octet)
 {
	unsigned int	bit;
	int	i = 7;

	while (i >= 0)
	{
		bit = (((octet >> i) & 1) + '0');
		write(1, &bit, 1);
		i--;
	}
 }

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

//  int	main(void)
// {
// 	print_bits(0);
// 	ft_putchar('\n');
// 	print_bits(1);
// 	ft_putchar('\n');
// 	print_bits(2);
// 	ft_putchar('\n');
// 	print_bits(3);
// 	ft_putchar('\n');
// 	print_bits(42);
// 	ft_putchar('\n');
// 	print_bits(69);
// 	ft_putchar('\n');
// 	return (0);
// }