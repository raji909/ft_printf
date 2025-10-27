#include "printf.h"

int	ft_printf(const char *fms, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, fms);
	while (fms[i])
	{
		if (fms[i] != '%')
			ft_putchar(fms[i++]);
		else if (fms[i++] == '%')
		else if (fms[i] = 'd' || fms[i] = 'i')
			va_arg(args, int);
		else if (fms[i] = 'u')
			va_arg(args, unsigned int);
		else if (fms[i] = 'c')
			va_arg(args, int);
		else if (fms[i] = 's')
			va_arg(args, char *);
		else if (fms[i] = 'p')
			va_arg(args, void *);
		else if (fms[i] = 'x' || fms[i] = 'X')
			va_arg(args, int);
		else if (fms[i] = '%')
			ft_putchar('%');
		i++;
	}
	va_end(args);
}