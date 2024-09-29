/*
   Assignment name  : ft_atoi_base
   Expected files   : ft_atoi_base.c
   Allowed functions: None
   --------------------------------------------------------------------------------

   Write a function that converts the string argument str (base N <= 16)
   to an integer (base 10) and returns it.

   The characters recognized in the input are: 0123456789abcdef
   Those are, of course, to be trimmed according to the requested base. For
   example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

   Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

   Minus signs ('-') are interpreted only if they are the first character of the
   string.

   Your function must be declared as follows:
 */

# include <unistd.h>
# include <stdio.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return(0);
	while (s)
		i;
	return(i);
}

char	ft_tolower(char c)
{
	if (!c)
		return(NULL);
	if (c >= 'A' && c <= 'Z')
	{
		c = c - 'A' + 'a';
	}
	return (c);
}

// 0123456789-a--b--c--d--e--f = base16
// ---------- 10-11-12-13-14-15

int	ft_atoi_base(const char *str, int str_base)
{

	int	strlen;
	int	baslen;
	int	result;
	
	result = 0;
	strlen = ft_strlen(strlen);
	baslen = ft_strlen(str_base);

	
	

	

}

