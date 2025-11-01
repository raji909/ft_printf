/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plusflag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:30:28 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 13:23:44 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_plus_switch(char *num, const char fms, int size)
{
	int		len;
	char	*space;

	if (fms == 'd' || fms == 'i')
	{
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

int	ft_plusflag(va_list args, const char *fms, int size)
{
	int		i;
	int		n;
	char	*num;
	char	*result;

	i = 0;
	while (ft_isdigit(fms[i]) || fms[i] == '+')
		i++;
	if (fms[i] == '+')
	{
		n = va_arg(args, int);
		num = ft_itoa(n);
		if (!num)
			return (0);
		if (n < 0)
			return (ft_putstr(ft_plus_switch(num, fms[i], size)));
		result = ft_plus_switch(ft_strjoin("+", num), fms[i], size);
		free(num);
		return (ft_putstr(result));
	}
	return (0);
}
