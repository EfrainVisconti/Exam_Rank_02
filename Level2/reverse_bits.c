// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0100  0001
//      ||
//      \/
//  1000  0010

// unsigned char	reverse_bits(unsigned char octet)
// {
// 	int		i = 7;
// 	unsigned char	res = 0;

// 	while (i >= 0)
// 	{
// 		res = res * 2 + (octet % 2);
// 		octet = octet / 2;
// 		i--;
// 	}
// 	return (res);
// }

unsigned char	reverse_bits(unsigned char octet) {
    unsigned char	reversed;
    int	i;

    reversed = 0;
	i = 0;
    while (i < 8) {
        reversed <<= 1;           // Shift the result to the left to make room for the next bit
        reversed |= (octet & 1);  // Add the least significant bit of octet to reversed
        octet >>= 1;              // Shift octet to the right to process the next bit
        i++;                      // Increment the loop counter
    }
    
    return reversed;
}

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	print_bits(200);
	ft_putchar('\n');
	print_bits(reverse_bits(200));
	ft_putchar('\n');
}