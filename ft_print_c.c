/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:11:39 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 05:03:47 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_no_ngt(t_struct *fplist, unsigned char ap_arg)
{
	fplist->width = fplist->width - 1;
	while (fplist->width)
	{
		(fplist->zero == 1) ? ft_putchar('0') : ft_putchar(' ');
		fplist->width--;
	}
	ft_putchar(ap_arg);
}

void				ft_print_c(t_struct *fplist, va_list ap)
{
	unsigned char	ap_arg;

	ap_arg = va_arg(ap, int);
	if (fplist->width > 1)
	{
		if (fplist->ngt == 1)
		{
			ft_putchar(ap_arg);
			fplist->width = fplist->width - 1;
			while (fplist->width)
			{
				ft_putchar(' ');
				fplist->width--;
			}
		}
		else
			ft_no_ngt(fplist, ap_arg);
	}
	else
		ft_putchar(ap_arg);
}
