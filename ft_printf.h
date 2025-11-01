/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:09:44 by adraji            #+#    #+#             */
/*   Updated: 2025/11/01 13:30:13 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

// # define INT_MAX 2147483647

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

int	ft_printf_bonus(va_list args, const char *fms);
int	ft_dashflag(va_list args, const char *fms,  int size);
int	ft_digitflag(va_list args, const char *fms, int size);
int	ft_doteflag(va_list args, const char *fms, int size);
int	ft_hashflag(va_list args, const char *fms, int size);
int	ft_plusflag(va_list args, const char *fms, int size);
int	ft_spaceflag(va_list args, const char *fms, int size);
int	ft_zeroflag(va_list args, const char *fms, int size);

#endif
