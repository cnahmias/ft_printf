/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:49:24 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 14:23:23 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct		s_ptf
{
	int				moins;
	int				space;
	int				zero;
	int				width1;
	int				width2;
	int				start;
	int				flag;
	int				point;
	int				precis;
	int				num1;
	int				num2;
	int				end;
	int				letter;
	va_list			*val;
	int				ret;
	int				star1;
	int				star2;
}					t_ptf;

int					ft_star(int i, t_ptf *ptf, int ret);
unsigned long		ft_transform(int num);
long				ft_abs(int i);
int					ft_max(int n1, int n2);
int					ft_lennum(long i);
int					ft_min(int n1, int n2);
int					ft_lenx(unsigned long i);
int					ft_lennum_abs(long i);
int					ft_strlen(char *src);
int					ft_increase(t_ptf *ptf, int i);
void				ft_putchar(char c, t_ptf *ptf);
void				ft_putchar_long(char *str, int len, t_ptf *ptf);
void				ft_putnbr(long nb, t_ptf *ptf);
void				ft_putnbr_x(unsigned long nb, t_ptf *ptf);
void				ft_putnbr_xm(unsigned long nb, t_ptf *ptf);
int					ft_start(char *src, t_ptf *ptf, int i);
int					ft_printf(char *src, ...);
void				ft_reading_2(char *str, int i, t_ptf *ptf);
void				ft_reading(char *str, int i, t_ptf *ptf);
bool				ft_isnum(char c);
int					find_index(char *tab, char element);
void				my_printf_null(char *src, t_ptf *ptf);
void				ft_init(char *src, t_ptf *ptf);
void				ft_treat(char *src, t_ptf *ptf);
void				ft_num1(t_ptf *ptf, char *src);
void				ft_precis(t_ptf *ptf);
void				ft_num2(t_ptf *ptf, char *src);
int					my_printf_c(t_ptf *ptf);
int					my_printf_s(t_ptf *ptf);
void				ft_printf_s_1(t_ptf *ptf, char *str);
void				ft_printf_s_2(t_ptf *ptf, char *str);
void				ft_printf_s_3(t_ptf *ptf, char *str);
void				ft_printf_s_4(t_ptf *ptf, char *str);
void				ft_printf_xm_1(t_ptf *ptf, unsigned long str);
void				ft_printf_xm_2(t_ptf *ptf, unsigned long str);
int					my_printf_xm(t_ptf *ptf);
void				ft_printf_x_1(t_ptf *ptf, unsigned long str);
void				ft_printf_x_2(t_ptf *ptf, unsigned long str);
int					my_printf_x(t_ptf *ptf);
void				ft_printf_i_1(t_ptf *ptf, int str);
void				ft_printf_i_2(t_ptf *ptf, int str);
int					my_printf_i(t_ptf *ptf);
void				ft_printf_p_1(t_ptf *ptf, long nb);
void				ft_printf_p_2(t_ptf *ptf, long nb);
int					my_printf_p(t_ptf *ptf);
int					my_printf_u(t_ptf *ptf);
void				ft_printf_u_1(t_ptf *ptf, long str);
void				ft_printf_u_2(t_ptf *ptf, long str);
int					my_printf_pc(t_ptf *ptf);

#endif
