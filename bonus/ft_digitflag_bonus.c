/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitflag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:03:56 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 13:24:47 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_digit_switch(va_list args, const char fms, int size)
{
	int		len;
	char	*num;
	char	*space;

	if (fms == 'd' || fms == 'i')
	{
		num = ft_itoa(va_arg(args, int));
		if (!num)
			return (NULL);
		len = size - ft_strlen(num);
		if (len < 0)
			return (num);
		space = malloc(sizeof(char) * (len + 1));
		if (!space)
		{
			free(num);
			return (NULL);
		}
		ft_memset(space, ' ', len);
		space[len] = '\0';
		return (ft_strjoin(space, num));
	}
	return (NULL);
}

int	ft_digitflag(va_list args, const char *fms, int size)
{
	int		i;
	char	*s;

	i = 0;
	if (size < 0)
		return (0);
	while (ft_isdigit(fms[i]))
		i++;
	s = ft_digit_switch(args, fms[i], size);
	if (!s)
		return (0);
	return (ft_putstr(s));
}
