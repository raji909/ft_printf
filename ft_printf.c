#include "ft_printf.h"

int	ft_printf(const char *fms, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, fms);
	while (fms[i])
	{
		if (fms[i] != '%')
			count += ft_putchar(fms[i]);
		else
		{
			i++;
			if (fms[i] == 'd' || fms[i] == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (fms[i] == 'u')
				count += ft_putunbr(va_arg(args, unsigned int));
			else if (fms[i] == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (fms[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (fms[i] == 'p')
				count += ft_putaddress(va_arg(args, void *));
			else if (fms[i] == 'x' || fms[i] == 'X')
				count += ft_puthexa(va_arg(args, unsigned int), fms[i]);
			else if (fms[i] == '%')
				count += ft_putchar('%');
		}
		i++;
	}
	va_end(args);
	return (count);
}
