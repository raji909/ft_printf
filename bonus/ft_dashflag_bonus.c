/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dashflag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:07:52 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 13:40:42 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_char_case(const char c)
{
	char	*s;

	s = malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

static char	*ft_dash_switch(va_list args, const char fms)
{
	if (fms == 'd' || fms == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (fms == 'u')
		return (ft_utoa(va_arg(args, unsigned int)));
	else if (fms == 'c')
		return (ft_char_case((char)va_arg(args, int)));
	else if (fms == 's')
		return (ft_strdup(va_arg(args, char *)));
	else if (fms == 'p')
		return (ft_address(va_arg(args, void *)));
	else if (fms == 'x' || fms == 'X')
		return (ft_hexa(va_arg(args, unsigned int), fms));
	else if (fms == '%')
		return (ft_char_case('%'));
	return (NULL);
}

int	ft_dashflag(va_list args, const char *fms, int size)
{
	int		i;
	int		count;
	char	*s;

	i = 0;
	if (size < 0)
		return (0);
	while (ft_isdigit(fms[i]) || fms[i] == '-')
		i++;
	s = ft_dash_switch(args, fms[i]);
	if (!s)
		return (0);
	count = ft_putstr(s);
	while (count < size)
		count += ft_putchar(' ');
	return (count);
}
