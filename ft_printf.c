/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init(char *src, t_ptf *ptf)
{
	int i;

	ptf->zero = 0;
	ptf->moins = 0;
	ptf->point = 0;
	if (ptf->star1 == 0)
		ptf->width1 = 0;
	else if (ptf->width1 < 0)
		ptf->moins = 1;
	ptf->width1 = ft_abs(ptf->width1);
	if ((ptf->star2 == 0) || (ptf->width2 < 0))
		ptf->width2 = -1;
	i = ptf->start;
	while (i < ptf->flag)
	{
		if (src[i] == '0')
			ptf->zero = 1;
		else if (src[i] == '-')
			ptf->moins++;
		i++;
	}
	if ((ptf->moins != 0) && (ptf->letter != 8))
		ptf->zero = 0;
}

void	ft_treat(char *src, t_ptf *ptf)
{
	int (*tab_function[9])(t_ptf *ptf);

	tab_function[0] = my_printf_c;
	tab_function[1] = my_printf_s;
	tab_function[2] = my_printf_p;
	tab_function[3] = my_printf_i;
	tab_function[4] = my_printf_i;
	tab_function[5] = my_printf_u;
	tab_function[6] = my_printf_x;
	tab_function[7] = my_printf_xm;
	tab_function[8] = my_printf_pc;
	ft_init(src, ptf);
	if (ptf->num1 != ptf->flag)
		ft_num1(ptf, src);
	if (ptf->precis != ptf->num1)
		ft_precis(ptf);
	if (ptf->num2 != ptf->precis)
		ft_num2(ptf, src);
	if ((ptf->num2 == ptf->precis) && (ptf->point == 1))
		ptf->width2 = 0;
	tab_function[ptf->letter](ptf);
}

void	ft_reading(char *src, int i, t_ptf *ptf)
{
	ptf->start = i;
	while (src[i] == '-' || src[i] == '0' || src[i] == ' ')
		i++;
	ptf->flag = i;
	while (ft_isnum(src[i]) == true)
		i++;
	ptf->num1 = i;
	if ((ptf->flag == ptf->num1) && (src[i] == '*'))
	{
		ptf->star1++;
		ptf->width1 = va_arg(*ptf->val, int);
		ptf->num1++;
		i++;
	}
	if (src[i] == '.')
		i++;
	ptf->precis = i;
	ft_reading_2(src, i, ptf);
}

void	ft_reading_2(char *src, int i, t_ptf *ptf)
{
	char *tab_index;

	tab_index = "cspdiuxX%";
	while (ft_isnum(src[i]) == true)
		i++;
	ptf->num2 = i;
	if ((ptf->precis == ptf->num2) && (src[i] == '*'))
	{
		ptf->star2++;
		ptf->width2 = va_arg(*ptf->val, int);
		ptf->num2++;
		i++;
	}
	ptf->end = i + 1;
	if (find_index(tab_index, src[i]) == -1)
		my_printf_null(src, ptf);
	else if (find_index(tab_index, src[i]) != -1)
	{
		ptf->letter = find_index(tab_index, src[i]);
		ft_treat(src, ptf);
	}
}

int		ft_printf(char *src, ...)
{
	int		i;
	t_ptf	*ptf;
	va_list val;

	va_start(val, src);
	i = 0;
	ptf = malloc(sizeof(t_ptf));
	ptf->val = &val;
	ptf->end = 0;
	ptf->ret = 0;
	while ((src[i] != (int)0) && (i < ft_strlen(src)))
	{
		while ((i < ft_strlen(src)) && (src[i] != '%') && (src[i]))
			ft_putchar(src[i++], ptf);
		ptf->star1 = 0;
		ptf->star2 = 0;
		if ((i <= (ft_strlen(src) - 1)) && src[i] == '%')
			i = ft_start(src, ptf, i);
	}
	va_end(val);
	i = ptf->ret;
	ptf->star1 = 0;
	ptf->star2 = 0;
	free(ptf);
	return (i);
}
