/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:44:05 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 04:57:54 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_while(t_struct *fplist, int i)
{
	if (i == 1)
	{
		while (fplist->width)
		{
			ft_putchar(' ');
			fplist->width--;
		}
	}
	else if (i == 2)
	{
		while (fplist->precision)
		{
			ft_putchar('0');
			fplist->precision--;
		}
	}
	else
	{
		while (fplist->width)
		{
			(fplist->zero == 1) ? ft_putchar('0') : ft_putchar(' ');
			fplist->width--;
		}
	}
}

static void			ft_larger_p_w(t_struct *fplist, int num_len,
					unsigned int ap_arg)
{
	if (fplist->width > fplist->precision)
	{
		fplist->width = fplist->width - fplist->precision;
		if (fplist->ngt == 0)
		{
			ft_while(fplist, 1);
			fplist->precision = fplist->precision - num_len;
			ft_while(fplist, 2);
			ft_putnbr(ap_arg, 10, fplist->type);
		}
		else
		{
			fplist->precision = fplist->precision - num_len;
			ft_while(fplist, 2);
			ft_putnbr(ap_arg, 10, fplist->type);
			ft_while(fplist, 1);
		}
	}
	else
	{
		fplist->precision = fplist->precision - num_len;
		ft_while(fplist, 2);
		ft_putnbr(ap_arg, 10, fplist->type);
	}
}

static void			ft_larger_w(t_struct *fplist, int num_len,
					unsigned int ap_arg)
{
	if (fplist->ngt == 1)
	{
		if (ap_arg == 0 && (fplist->precision != 1))
		{
			ft_while(fplist, 1);
		}
		else
		{
			ft_putnbr(ap_arg, 10, fplist->type);
			fplist->width = fplist->width - num_len;
			ft_while(fplist, 1);
		}
	}
	else
	{
		fplist->width = fplist->width - num_len;
		if (ap_arg == 0 && fplist->precision != 1)
			fplist->width += 1;
		ft_while(fplist, 3);
		if (ap_arg == 0 && fplist->precision != 1)
			return ;
		ft_putnbr(ap_arg, 10, fplist->type);
	}
}

static void			ft_smaller_s_w(t_struct *fplist, int num_len,
					unsigned int ap_arg)
{
	if (fplist->width > num_len)
		ft_larger_w(fplist, num_len, ap_arg);
	else
	{
		if (ap_arg == 0 && fplist->precision <= 0)
		{
			if (fplist->width == 0)
				return ;
			if (fplist->width == 1)
			{
				ft_putchar(' ');
				return ;
			}
		}
		ft_putnbr(ap_arg, 10, fplist->type);
	}
}

void				ft_print_u(t_struct *fplist, va_list ap)
{
	int				num_len;
	unsigned int	ap_arg;

	ap_arg = va_arg(ap, unsigned int);
	num_len = ft_num_len(ap_arg);
	if (fplist->precision > num_len)
		ft_larger_p_w(fplist, num_len, ap_arg);
	else
		ft_smaller_s_w(fplist, num_len, ap_arg);
}
