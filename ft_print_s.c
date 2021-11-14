/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:43:19 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 04:53:53 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_larger_width(t_struct *fplist, int str_len, char *ap_arg)
{
	fplist->width = fplist->width - str_len;
	if (fplist->ngt == 0)
	{
		while (fplist->width)
		{
			ft_putchar(' ');
			fplist->width--;
		}
		ft_putstr(ap_arg, str_len);
	}
	else
	{
		fplist->precision = fplist->precision - str_len;
		ft_putstr(ap_arg, str_len);
		while (fplist->width)
		{
			ft_putchar(' ');
			fplist->width--;
		}
	}
}

void				ft_print_s(t_struct *fplist, va_list ap)
{
	int				str_len;
	char			*ap_arg;

	ap_arg = va_arg(ap, char *);
	if (ap_arg == NULL)
	{
		ap_arg = "(null)";
	}
	str_len = ft_strlen(ap_arg);
	if ((fplist->precision > str_len) || (fplist->precision == -1))
	{
		if (fplist->width > str_len)
			ft_larger_width(fplist, str_len, ap_arg);
		else
			ft_putstr(ap_arg, str_len);
	}
	else
	{
		str_len = fplist->precision;
		if (fplist->width > str_len)
			ft_larger_width(fplist, str_len, ap_arg);
		else
			ft_putstr(ap_arg, str_len);
	}
}
