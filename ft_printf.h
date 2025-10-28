#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_printf(const char *fms, ...);
int		ft_putaddress(void *p);
int		ft_putchar(char c);
int		ft_puthexa(unsigned int n, char x);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putunbr(unsigned int n);
char	*ft_strcpy(char *dst, const char *src);

#endif