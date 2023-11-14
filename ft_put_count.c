/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:09 by eburnet           #+#    #+#             */
/*   Updated: 2023/11/14 12:07:34 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digits(long long int n)
{
	int	count;

	count = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_base(unsigned int n, char *base)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base);
	}
	ft_putchar(base[n % base_len]);
	return (ft_count_digits(n));
}

int	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
	}
	ft_putchar(n % 10 + 48);
	return (ft_count_digits(n));
}

int	ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + 48);
	return (ft_count_digits(n));
}

int	ft_putstr(char *s)
{
	int		i;

	if (s == NULL)
		s = "(null)";
	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
