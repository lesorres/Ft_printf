/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_functions_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:40:13 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 04:59:58 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char a)
{
	write(1, &a, 1);
	g_n_printed++;
}

void		ft_putstr(char *str, int str_len)
{
	int i;

	i = 0;
	while (str_len > 0)
	{
		ft_putchar(str[i]);
		i++;
		str_len--;
	}
}

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int			ft_ngt_arg(t_struct *fplist, int ap_arg, int i)
{
	if ((i == 1) && (ap_arg < 0))
	{
		fplist->width -= 1;
		return (ap_arg);
	}
	else if ((i == 2) && (ap_arg < 0))
	{
		ap_arg *= -1;
		ft_putchar('-');
		return (ap_arg);
	}
	else if ((i == 3) && (ap_arg < 0))
	{
		fplist->width -= 1;
		if (fplist->precision == 1 && fplist->zero == 1)
		{
			ap_arg *= -1;
			ft_putchar('-');
		}
		return (ap_arg);
	}
	return (ap_arg);
}

char		*ft_strchr(const char *s, int c)
{
	char	*ss;
	char	cc;
	int		i;

	ss = (char*)s;
	cc = (char)c;
	i = 0;
	while (*ss != '\0')
	{
		if (*ss == c)
			return (ss);
		ss++;
	}
	if (*ss == '\0' && cc == '\0')
		return (NULL);
	return (NULL);
}
