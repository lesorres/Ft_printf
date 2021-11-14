/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:05:00 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 04:54:18 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_ngt(t_struct *fplist, int num_len, unsigned long ap_arg)
{
	ft_putstr("0x", 2);
	if (!(!ap_arg && fplist->precision == -1))
		ft_putnbr_p(ap_arg, 16, fplist->type);
	fplist->width = fplist->width - (num_len + 2);
	while (fplist->width)
	{
		ft_putchar(' ');
		fplist->width--;
	}
}

static void			ft_non_ngt(t_struct *fplist, int num_len,
					unsigned long ap_arg)
{
	fplist->width = fplist->width - (num_len + 2);
	while (fplist->width)
	{
		if (fplist->zero == 0)
			ft_putchar(' ');
		fplist->width--;
	}
	ft_putstr("0x", 2);
	if (!(!ap_arg && fplist->precision == -1))
		ft_putnbr_p(ap_arg, 16, fplist->type);
}

void				ft_print_p(t_struct *fplist, va_list ap)
{
	int					num_len;
	unsigned long long	ap_arg;

	ap_arg = va_arg(ap, unsigned long long);
	num_len = ft_hex_num_len(ap_arg, fplist);
	(!ap_arg && (fplist->precision == -1)) ? num_len = 0 : num_len;
	if (fplist->width > (num_len + 2))
	{
		if (fplist->ngt == 1)
			ft_ngt(fplist, num_len, ap_arg);
		else
			ft_non_ngt(fplist, num_len, ap_arg);
	}
	else
	{
		ft_putstr("0x", 2);
		if (!(!ap_arg && fplist->precision == -1))
			ft_putnbr_p(ap_arg, 16, fplist->type);
	}
}
