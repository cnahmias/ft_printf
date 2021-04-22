/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_us.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		my_printf_u(t_ptf *ptf)
{
	int		str;
	long	num;

	str = va_arg(*ptf->val, int);
	num = 4294967295;
	if (str < 0)
		num = num + str + 1;
	else
		num = str;
	if (ptf->moins != 0)
		ft_printf_u_1(ptf, num);
	else if (ptf->moins == 0)
		ft_printf_u_2(ptf, num);
	return (1);
}

void	ft_printf_u_1(t_ptf *ptf, long str)
{
	int i;
	int max;
	int nb;

	i = 0;
	nb = ft_lennum(str);
	max = ft_max(ptf->width2, nb);
	while (i < (ptf->width2) - nb)
	{
		ft_putchar('0', ptf);
		i++;
	}
	if ((str == 0) && (ptf->width2 == 0) && (ptf->width1 != 0))
		ft_putchar(' ', ptf);
	else if ((str != 0) || (ptf->width2 != 0))
		ft_putnbr(str, ptf);
	i = max;
	while (i < (ptf->width1))
		i = ft_increase(ptf, i);
}

void	ft_printf_u_2(t_ptf *ptf, long str)
{
	int i;
	int max;
	int nb;

	i = 0;
	nb = ft_lennum(str);
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
		ft_putnbr(str, ptf);
}
