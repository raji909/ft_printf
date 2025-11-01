/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaceflag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:37:33 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 13:25:26 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_spase_switch(char *num, char const fms, int size)
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

int	ft_spaceflag(va_list args, const char *fms, int size)
{
	int		i;
	int		n;
	char	*num;
	char	*result;

	i = 0;
	while (ft_isdigit(fms[i]) || fms[i] == ' ')
		i++;
	if (fms[i] == '+')
	{
		n = va_arg(args, int);
		num = ft_itoa(n);
		if (!num)
			return (0);
		result = ft_spase_switch(num, fms[i], size);
		free(num);
		return (ft_putstr(result));
	}
	return (0);
}
