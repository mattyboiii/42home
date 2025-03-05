#include <unistd.h>

unsigned char	reverse_bits(unsigned char b)
{
	unsigned char	r;
	unsigned	byte_len;

	r = 0;
	byte_len = 8;
	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

void	print_bits(unsigned char octet)
{
	unsigned	idx;
	unsigned char	bit;

	idx = 8;
	while (idx--)
	{
		bit = ((octet >> idx & 1) + '0');
		write(1, &bit, 1);
	}
}

int	main(void)
{
	unsigned char c;

	print_bits(42);  // Binary representation of 42
	write(1, "\n", 1);

	print_bits(255); // Binary representation of 255
	write(1, "\n", 1);

	print_bits(0);   // Binary representation of 0
	write(1, "\n", 1);

	print_bits('A'); // Binary representation of 'A' (65 in ASCII)
	write(1, "\n", 1);

	c = '.';
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
