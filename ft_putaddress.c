#include "ft_printf.h"

static int	ft_printadd(size_t n, char *hexa)
{
	int count;

	count = 0;
	if (n > 15)
		count += ft_printadd(n / 16, hexa);
	count += ft_putchar(hexa[n % 16]);
	return (count);
}

int	ft_putaddress(void *p)
{
	char	hexa[17];
	size_t	add;
	int count;

	if (!p)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_strcpy(hexa, "0123456789abcdef");
	add = (size_t)p;
	ft_putstr("0x");
	count = ft_printadd(add, hexa);
	return (count);
}
