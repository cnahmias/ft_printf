/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_Xs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_start(char *src, t_ptf *ptf, int i)
{
	i++;
	ft_reading(src, i, ptf);
	i = (ptf->end);
	return (i);
}

int		my_printf_xm(t_ptf *ptf)
{
	int				str;
	unsigned long	num;

	str = va_arg(*ptf->val, int);
	num = ft_transform(str);
	if (ptf->moins != 0)
		ft_printf_xm_1(ptf, num);
	else if (ptf->moins == 0)
		ft_printf_xm_2(ptf, num);
	return (0);
}

void	ft_printf_xm_1(t_ptf *ptf, unsigned long str)
{
	int i;
	int nb;
	int max;

	i = 0;
	nb = ft_lenx(str);
	max = ft_max(ptf->width2, nb);
	while (i < (ptf->width2) - nb)
	{
		ft_putchar('0', ptf);
		i++;
	}
	if ((str == 0) && (ptf->width2 == 0) && (ptf->width1 != 0))
		ft_putchar(' ', ptf);
	else if ((str != 0) || (ptf->width2 != 0))
		ft_putnbr_xm(str, ptf);
	i = 0;
	while (i < (ptf->width1) - max)
		i = ft_increase(ptf, i);
}

void	ft_printf_xm_2(t_ptf *ptf, unsigned long str)
{
	int i;
	int nb;
	int max;

	i = 0;
	nb = ft_lenx(str);
	max = ft_max(ptf->width2, nb);
	while (i < (ptf->width1) - max)
		i = ft_increase(ptf, i);
	i = 0;
	while (i < (ptf->width2) - nb)
	{
		ft_putchar('0', ptf);
		i++;
	}
	if ((str == 0) && (ptf->width2 == 0) && (ptf->width1 != 0))
		ft_putchar(' ', ptf);
	else if ((str != 0) || (ptf->width2 != 0))
		ft_putnbr_xm(str, ptf);
}
