/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:24 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 16:42:55 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_bonus(va_list args, const char *fms)
{
	int		count;

	count = 0;
	if (fms[0] == '-')
		count += ft_dashflag(args, fms + 1, ft_atoi(fms + 1));
	else if (fms[0] == '.')
		count += ft_doteflag(args, fms + 1, ft_atoi(fms + 1));
	else if (fms[0] == '#')
		count += ft_hashflag(args, fms + 1, ft_atoi(fms + 1));
	else if (fms[0] == '0')
		count += ft_zeroflag(args, fms + 1, ft_atoi(fms + 1));
	else if (fms[0] == ' ')
		count += ft_spaceflag(args, fms + 1, ft_atoi(fms + 1));
	else if (fms[0] == '+')
		count += ft_plusflag(args, fms + 1, ft_atoi(fms + 1));
	else if (ft_isdigit(fms[0]))
		count += ft_digitflag(args, fms + 1, ft_atoi(fms));
	return (count);
}
