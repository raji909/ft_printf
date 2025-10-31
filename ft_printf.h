/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:44 by adraji            #+#    #+#             */
/*   Updated: 2025/10/31 16:11:45 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_printf(const char *fms, ...);
char	*ft_address(void *p);
char	*ft_utoa(unsigned int n);
char	*ft_hexa(unsigned int n, char x);

#endif
