/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:38:09 by eburnet           #+#    #+#             */
/*   Updated: 2023/11/13 15:14:54 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n >= (unsigned long)base_len)
	{
		ft_putnbr_base(n / base_len, base);
	}
	write(1, &base[n % base_len], 1);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10);
	}
	write(1, &((char []){n % 10 + 48}), 1);
}

int	ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + 48);
}

int	ft_putstr(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
