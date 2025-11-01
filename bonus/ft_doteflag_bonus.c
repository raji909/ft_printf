/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doteflag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:58:07 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 16:48:26 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_dote_switch(va_list args, const char fms)
{
	if (fms == 'd' || fms == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (fms == 'u')
		return (ft_utoa(va_arg(args, unsigned int)));
	else if (fms == 's')
		return (ft_strdup(va_arg(args, char *)));
	else if (fms == 'x' || fms == 'X')
		return (ft_hexa(va_arg(args, unsigned int), fms));
	return (NULL);
}

int	ft_doteflag(va_list args, const char *fms, int size)
{
	int		i;
	int		len;
	int		count;
	char	*s;

	i = 0;
	if (size < 0)
		return (0);
	while (ft_isdigit(fms[i]) || fms[i] == '.')
		i++;
	s = ft_dote_switch(args, fms[i]);
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
