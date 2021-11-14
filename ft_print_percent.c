/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:21:10 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 04:48:03 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_struct *fplist)
{
	if (fplist->width > 1)
	{
		if (fplist->ngt == 1)
		{
			ft_putchar(fplist->type);
			fplist->width = fplist->width - 1;
			while (fplist->width)
			{
				ft_putchar(' ');
				fplist->width--;
			}
		}
		else
		{
			fplist->width = fplist->width - 1;
			while (fplist->width)
			{
				(fplist->zero == 1) ? ft_putchar('0') : ft_putchar(' ');
				fplist->width--;
			}
			ft_putchar(fplist->type);
		}
	}
	else
		ft_putchar(fplist->type);
}
