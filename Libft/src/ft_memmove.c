//DESCRIPTION
//     The memmove() function copies len bytes from string src to string dst.  The two strings may overlap; the copy is
//     always done in a non-destructive manner. (this always means that it does not change the src untill the copy is done)
//
//RETURN VALUES
//     The memmove() function returns the original value of dst.


#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_f;
	char	*dst_l;
	char	*src_f;
	char	*src_l;

	dst_f = (char *)dst;
	src_f = (char *)src;
	if(!dst && !src)
		return (NULL);
	if(dst_f < src_f)
	{
		while(len--)
			*dst_f++ = *src_f++;
	}
	else
	{
			dst_l = dst_f + (len-1);
			src_l = src_f + (len-1);
			while (len--)
				*dst_l-- = *src_l--;
		}
		return (dst);
}
