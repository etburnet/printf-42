/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:23:18 by eburnet           #+#    #+#             */
/*   Updated: 2023/11/14 11:56:47 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_p(va_list ap)
{
	unsigned long	adress;
	int				i;

	i = 2;
	adress = va_arg(ap, unsigned long long int);
	ft_putstr("0x");
	i += ft_putnbr_base(adress, "0123456789abcdef");
	return (i);
}

int	ft_type_management(const char *format, va_list ap)
{
	int	len;

	len = 0;
	format++;
	if (*format == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (*format == 'x')
		len += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*format == 'X')
		len += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*format == '%')
		len += ft_putchar('%');
	else if (*format == 'p')
		len += ft_p(ap);
	else if (*format == 'u')
		len += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else
		return (1);
	return (len);
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
			len += ft_type_management(format, ap);
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
	return (len);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_printf(" %x ", 0));
	printf("%d\n\n", printf(" %x ", 0));
	printf("%d\n", ft_printf(" %x ", -5));
	printf("%d\n\n", printf(" %x ", -5));
	printf("%d\n", ft_printf(" %x ", 1));
	printf("%d\n\n", printf(" %x ", 1));
	printf("%d\n", ft_printf(" %x ", 9));
	printf("%d\n\n", printf(" %x ", 9));
	printf("%d\n", ft_printf(" %x ", 10));
	printf("%d\n\n", printf(" %x ", 10));
	printf("%d\n", ft_printf(" %x ", 11));
	printf("%d\n\n\n", printf(" %x ", 11));
	printf("%d\n", ft_printf(" %x ", -10));
	printf("%d\n\n", printf(" %x ", -10));
	printf("%d\n", ft_printf(" %x ", -11));
	printf("%d\n\n", printf(" %x ", -11));
} */