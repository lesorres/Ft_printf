/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_functions_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 03:18:38 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 05:04:29 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_putnbr_p(unsigned long long k, unsigned int x,
						char c)
{
	if (k >= (unsigned long long)x)
	{
		ft_putnbr_p(k / x, x, c);
		ft_putnbr_p(k % x, x, c);
	}
	else
	{
		if (k <= 9)
			ft_putchar(k + 48);
		else if (c == 'X')
			ft_putchar(k + 55);
		else
			ft_putchar(k + 87);
	}
}

void					ft_putnbr(long long k, int x, char c)
{
	if (k < 0)
	{
		k *= -1;
		ft_putchar('-');
	}
	if (k >= (long long)x)
	{
		ft_putnbr(k / x, x, c);
		ft_putnbr(k % x, x, c);
	}
	else
	{
		if (k <= 9)
			ft_putchar(k + 48);
		else if (c == 'X')
			ft_putchar(k + 55);
		else
			ft_putchar(k + 87);
	}
}

int						ft_num_len(long n)
{
	int					i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int						ft_hex_num_len(unsigned long long nb, t_struct *fplist)
{
	unsigned long long	k;

	k = nb;
	if (k >= 16)
	{
		ft_hex_num_len(k / 16, fplist);
		ft_hex_num_len(k % 16, fplist);
	}
	else
		fplist->hexlen += 1;
	return (fplist->hexlen);
}

int						ft_atoi(char *str)
{
	int rslt;
	int	ngt;
	int	i;

	ngt = 1;
	rslt = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		ngt = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		rslt = rslt * 10 + (str[i] - 48);
		i++;
	}
	return (rslt * ngt);
}
