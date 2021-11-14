/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeeseek <kmeeseek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:26:06 by kmeeseek          #+#    #+#             */
/*   Updated: 2021/01/30 04:50:50 by kmeeseek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		g_n_printed;

typedef struct	s_struct
{
	int		ngt;
	int		zero;
	int		width;
	int		precision;
	char	type;
	int		hexlen;
}				t_struct;

int				ft_printf(const char *format, ...);
int				ft_parser(t_struct *list, const char *format, va_list ap);
void			ft_print_i_d(t_struct *fplist, va_list ap);
void			ft_print_u(t_struct *fplist, va_list ap);
void			ft_print_x(t_struct *fplist, va_list ap);
void			ft_print_p(t_struct *fplist, va_list ap);
void			ft_print_percent(t_struct *fplist);
void			ft_print_c(t_struct *fplist, va_list ap);
void			ft_print_s(t_struct *fplist, va_list ap);
void			ft_putchar(char a);
void			ft_putnbr(long long nb, int x, char c);
void			ft_putnbr_p(unsigned long long k, unsigned int x, char c);
void			ft_putstr(char *str, int str_len);
int				ft_atoi(char *str);
int				ft_num_len(long num);
int				ft_hex_num_len(unsigned long long nb, t_struct *fplist);
int				ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
int				ft_ngt_arg(t_struct *fplist, int ap_arg, int i);

#endif
