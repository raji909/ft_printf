#include "ft_printf.h"

static int	ft_print(unsigned int n, char *hexa)
{
	int count;

	count = 0;
	if (n > 15)
		count += ft_print(n / 16, hexa);
	count += ft_putchar(hexa[n % 16]);
	return (count);
}

int	ft_puthexa(unsigned int n, char x)
{
	char	hexa[17];
	int		count;

	if (x == 'X')
		ft_strcpy(hexa, "0123456789ABCDEF");
	else
		ft_strcpy(hexa, "0123456789abcdef");
	count = ft_print(n, hexa);
	return (count);
}
