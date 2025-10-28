#include "ft_printf.h"

static int	ft_switch(va_list args, char fms)
{
	if (fms == 'd' || fms == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (fms == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (fms == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (fms == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (fms == 'p')
		return (ft_putaddress(va_arg(args, void *)));
	else if (fms == 'x' || fms == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), fms));
	else if (fms == '%')
		return (ft_putchar('%'));
	return (0);
}

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
			if (fms[i])
				count += ft_switch(args, fms[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
