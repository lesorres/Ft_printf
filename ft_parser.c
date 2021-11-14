/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:37:19 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 04:56:55 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag_checker(int i, t_struct *list, const char *format)
{
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
		{
			list->ngt = 1;
			i++;
		}
		else if (format[i] == '0')
		{
			list->zero = 1;
			i++;
		}
	}
	return (i);
}

static int	ft_width_checker(int i, t_struct *list, const char *format,
			va_list ap)
{
	if (format[i] == '*')
	{
		if ((list->width = va_arg(ap, int)) < 0)
		{
			list->ngt = 1;
			list->width *= -1;
		}
		i++;
	}
	else if (format[i] >= 48 && format[i] <= 57)
	{
		list->width = ft_atoi((char *)&format[i]);
		while (format[i] >= 48 && format[i] <= 57)
			i++;
	}
	return (i);
}

static int	ft_precision_cheker_add(int i, t_struct *list, const char *format)
{
	list->precision = 0;
	while ((format[i] >= 48 && format[i] <= 57)
	|| format[i] == '-')
		i++;
	if (format[i] != '%')
		list->zero = 0;
	return (i);
}

static int	ft_precision_cheker(int i, t_struct *list, const char *format,
			va_list ap)
{
	if (format[i] == '*')
	{
		if ((list->precision = va_arg(ap, int)) < 0)
		{
			list->precision = 1;
			if (format[(i + 1)] == 's')
				list->precision = -1;
		}
		else if (format[(i + 1)] != '%')
			list->zero = 0;
		i++;
	}
	else if (format[i] >= 48 && format[i] <= 57)
	{
		list->precision = ft_atoi((char *)&format[i]);
		while (format[i] >= 48 && format[i] <= 57)
			i++;
		if (format[i] != '%')
			list->zero = 0;
	}
	else if (format[i] == 'p')
		list->precision = -1;
	else
		i = ft_precision_cheker_add(i, list, format);
	return (i);
}

int			ft_parser(t_struct *list, const char *format, va_list ap)
{
	int		i;

	i = 0;
	i = ft_flag_checker(i, list, format);
	i = ft_width_checker(i, list, format, ap);
	if (format[i] == '.')
	{
		i++;
		i = ft_precision_cheker(i, list, format, ap);
	}
	else
	{
		if (format[i] == 's')
			list->precision = -1;
	}
	if (list->ngt == 1)
		list->zero = 0;
	list->type = format[i++];
	if (!(ft_strchr("%cspdiuxX", format[i - 1])))
		return (-1);
	return (i);
}
