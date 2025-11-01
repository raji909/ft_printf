/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:54 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 13:38:07 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_hexalen(unsigned int n)
{
	int	len;

	len = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*ft_fillhexa(char *hexa, unsigned int n, const char *base)
{
	int	i;

	i = ft_hexalen(n);
	hexa[i--] = '\0';
	if (!n)
	{
		hexa[0] = '0';
		return (hexa);
	}
	while (n > 0)
	{
		hexa[i--] = base[n % 16];
		n /= 16;
	}
	return (hexa);
}

char	*ft_hexa(unsigned int n, char x)
{
	int		len;
	char	*hexa;

	len = ft_hexalen(n);
	hexa = malloc(len + 1);
	if (!hexa)
		return (NULL);
	if (x == 'X')
		ft_fillhexa(hexa, n, "0123456789ABCDEF");
	else
		ft_fillhexa(hexa, n, "0123456789abcdef");
	return (hexa);
}
