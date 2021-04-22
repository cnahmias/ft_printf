/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_s_3(t_ptf *ptf, char *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = 0;
	if (len < (ptf->width1))
	{
		while (i < (ptf->width1) - len)
		{
			ft_putchar(' ', ptf);
			i++;
		}
	}
	ft_putchar_long(str, len, ptf);
}

void	ft_printf_s_4(t_ptf *ptf, char *str)
{
	int i;
	int len;
	int min;

	i = 0;
	len = ft_strlen(str);
	min = ft_min(len, ptf->width2);
	while (i < (ptf->width1) - min)
	{
		ft_putchar(' ', ptf);
		i++;
	}
	i = 0;
	while (i < min)
	{
		ft_putchar(str[i], ptf);
		i++;
	}
}

int		my_printf_pc(t_ptf *ptf)
{
	int i;

	i = 0;
	if (ptf->moins > 0)
	{
		ft_putchar('%', ptf);
		i++;
		while (i < ptf->width1)
		{
			ft_putchar(' ', ptf);
			i++;
		}
		return (0);
	}
	while (i < ptf->width1 - 1)
	{
		if (ptf->zero == 0)
			ft_putchar(' ', ptf);
		else
			ft_putchar('0', ptf);
		i++;
	}
	ft_putchar('%', ptf);
	return (0);
}

int		ft_increase(t_ptf *ptf, int i)
{
	int a;

	a = i;
	if (ptf->zero == 1)
		ft_putchar('0', ptf);
	else if (ptf->zero == 0)
		ft_putchar(' ', ptf);
	a++;
	return (a);
}
