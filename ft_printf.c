/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:40 by adraji            #+#    #+#             */
/*   Updated: 2025/10/31 16:56:09 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_switch(va_list args, char fms)
{
	if (fms == 'd' || fms == 'i')
		return (ft_putstr(ft_itoa(va_arg(args, int))));
	else if (fms == 'u')
		return (ft_putstr(ft_utoa(va_arg(args, unsigned int))));
	else if (fms == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (fms == 's')
		return (ft_putstr(ft_strdup(va_arg(args, char *))));
	else if (fms == 'p')
		return (ft_putstr(ft_address(va_arg(args, void *))));
	else if (fms == 'x' || fms == 'X')
		return (ft_putstr(ft_hexa(va_arg(args, unsigned int), fms)));
	else if (fms == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *fms, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	if (!fms)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, fms);
	while (fms[i])
	{
		if (fms[i] != '%')
			count += ft_putchar(fms[i]);
		// else if (fms[i + 1] == ' ' || fms[i + 1] == '.' ||
		// 	fms[i + 1] == '-' || fms[i + 1] == '#' || ft_isdigit(fms[i + 1]))
		// 	count += ft_printf_bonus(args, &fms[++i]);
		else if (fms[i + 1])
			count += ft_switch(args, fms[++i]);
		i++;
	}
	va_end(args);
	return (count);
}
