/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:06:52 by eburnet           #+#    #+#             */
/*   Updated: 2023/11/13 15:08:00 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		ft_putnbr_base(unsigned long n, char *base);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_strlen(char *s);
#endif