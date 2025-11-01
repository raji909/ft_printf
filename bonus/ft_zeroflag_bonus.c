/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroflag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:28:06 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 13:13:57 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_zero_switch(va_list args, const char fms)
{
	if (fms == 'd' || fms == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (fms == 'u')
		return (ft_utoa(va_arg(args, unsigned int)));
	else if (fms == 'x' || fms == 'X')
		return (ft_hexa(va_arg(args, unsigned int), fms));
	return (NULL);
}

int	ft_zeroflag(va_list args, const char *fms, int size)
{
	int		i;
	int		len;
	int		count;
	char	*s;

	i = 0;
	if (size < 0)
		return (0);
	while (ft_isdigit(fms[i]))
		i++;
	s = ft_zero_switch(args, fms[i]);
	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	count = 0;
	while (len + i < size)
	{
		count += ft_putchar('0');
		i++;
	}
	count += ft_putstr(s);
	return (count);
}
