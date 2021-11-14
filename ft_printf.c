/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 00:57:07 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 04:52:29 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_processor(t_struct *fplist, va_list ap)
{
	if (fplist->type == 'i' || fplist->type == 'd')
		ft_print_i_d(fplist, ap);
	if (fplist->type == 'u')
		ft_print_u(fplist, ap);
	if (fplist->type == 'c')
		ft_print_c(fplist, ap);
	if (fplist->type == 's')
		ft_print_s(fplist, ap);
	if (fplist->type == 'p')
		ft_print_p(fplist, ap);
	if (fplist->type == 'x' || fplist->type == 'X')
		ft_print_x(fplist, ap);
	if (fplist->type == '%')
		ft_print_percent(fplist);
}

static void		ft_fplist_init(t_struct *fplist)
{
	fplist->ngt = 0;
	fplist->zero = 0;
	fplist->width = 0;
	fplist->precision = 1;
	fplist->type = '\0';
	fplist->hexlen = 0;
}

static int		ft_met_percent(int i, const char *format,
				t_struct fplist, va_list ap)
{
	int			z;

	i++;
	if (format[i] == '%')
		ft_putchar(format[i++]);
	else
	{
		z = ft_parser(&fplist, &format[i], ap);
		if (z == -1)
			return (-1);
		else
			i = i + z;
		ft_processor(&fplist, ap);
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	fplist;
	int			i;

	g_n_printed = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		ft_fplist_init(&fplist);
		if (format[i] == '%')
		{
			i = ft_met_percent(i, format, fplist, ap);
			if (i == -1)
				return (0);
		}
		else
			ft_putchar(format[i++]);
	}
	va_end(ap);
	return (g_n_printed);
}
