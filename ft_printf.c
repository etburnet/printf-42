/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:23:18 by eburnet           #+#    #+#             */
/*   Updated: 2023/11/12 16:27:33 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libftprintf.h"

void	ft_type_management(const char *format, va_list ap)
{
	format++;
	ap++;
	if (*format == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*format == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*format == 'x' || *format == 'X')
		;
	else if (*format == '%')
		write(1, "%%", 1);
	else if (*format == 'p')
		;
	else if (*format == 'u')
		;
	else
		return;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start (ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_type_management(format, ap);
		}
		else
		{
			while (*format != '\0' && *format != '%')
			{
				write(1, format, 1);
				format++;
			}
		}
		format++;
	}
	va_end(ap);
	return (0);
}
\
int main(void)
{
	ft_printf("Salut les %d gars", 5);
}