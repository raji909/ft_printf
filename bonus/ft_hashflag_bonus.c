/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashflag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:49:38 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 13:40:53 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_hash_switch(va_list args, const char fms)
{
	char	*hash;
	char	*hexa;
	char	*result;

	if (fms == 'x' || fms == 'X')
	{
		hash = malloc(sizeof(char) * 3);
		if (!hash)
			return (NULL);
		hash[0] = '0';
		hash[1] = fms;
		hash[2] = '\0';
		hexa = ft_hexa(va_arg(args, unsigned int), fms);
		if (!hexa)
			free(hash);
		result = ft_strjoin(hash, hexa);
		if (!result)
			return (NULL);
		free(hash);
		free(hexa);
		return (result);
	}
	return (NULL);
}

int	ft_hashflag(va_list args, const char *fms, int size)
{
	int		i;
	int		len;
	int		count;
	char	*s;

	i = 0;
	if (size < 0)
		return (0);
	while (ft_isdigit(fms[i]) || fms[i] == '#')
		i++;
	s = ft_hash_switch(args, fms[i]);
	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	count = 0;
	while (len + i < size)
	{
		count += ft_putchar(' ');
		i++;
	}
	count += ft_putstr(s);
	return (count);
}
