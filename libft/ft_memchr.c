/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:59:44 by adraji            #+#    #+#             */
/*   Updated: 2025/10/15 16:21:54 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		ch;

	i = 0;
	str = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ch == str[i])
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
