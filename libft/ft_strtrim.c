/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:02:36 by adraji            #+#    #+#             */
/*   Updated: 2025/10/17 18:02:38 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_lentrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	f;

	i = 0;
	f = ft_strlen(s1) - 1;
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	if (i > f)
		return (0);
	while (ft_isset(s1[f], set))
		f--;
	return ((f - i) + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set || !*set)
		return (ft_strdup(s1));
	i = 0;
	len = ft_lentrim(s1, set);
	if (!len)
		return (ft_strdup(""));
	trim = malloc(sizeof (char) * (len + 1));
	if (!trim)
		return (NULL);
	while (ft_isset(*s1, set))
		s1++;
	while (i < len)
		trim[i++] = *(s1++);
	trim[i] = '\0';
	return (trim);
}
