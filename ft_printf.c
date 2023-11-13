/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:23:18 by eburnet           #+#    #+#             */
/*   Updated: 2023/11/13 15:13:49 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_type_management(const char *format, va_list ap)
{
	format++;
	if (*format == 'c')
		ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		ft_putstr(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (*format == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*format == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*format == '%')
		ft_putchar('%');
	else if (*format == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_base(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	else if (*format == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start (ap, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			len = len + ft_type_management(format, ap);
			format = format + 2;
		}
		while (*format != '\0' && *format != '%')
		{
			ft_putchar((char)*format);
			format++;
			len++;
		}
	}
	va_end(ap);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	ft_printf("Salut %% les %d gars %d %d, %s%c\n", 5, 10, 15, "cv ", '?');
	printf("Salut %% les %d gars %d %d, %s%c\n", 5, 10, 15, "cv ", '?');
}
