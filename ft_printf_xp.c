/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned long	ft_transform(int num)
{
	unsigned long trans;

	if (num >= 0)
		return (num);
	else
	{
		trans = 4294967296 + num;
		return (trans);
	}
}

int				ft_lenx(unsigned long i)
{
	int				len;
	unsigned long	nb;

	len = 0;
	nb = i;
	if (i == 0)
		return (1);
	if (i < 0)
		nb = -i;
	while (nb > 0)
	{
		len++;
		nb = (nb / 16);
	}
	return (len);
}

int				my_printf_x(t_ptf *ptf)
{
	int				str;
	unsigned long	num;

	str = va_arg(*ptf->val, int);
	num = ft_transform(str);
	if (ptf->moins != 0)
		ft_printf_x_1(ptf, num);
	if (ptf->moins == 0)
		ft_printf_x_2(ptf, num);
	return (0);
}

void			ft_printf_x_1(t_ptf *ptf, unsigned long str)
{
	int i;
	int max;
	int nb;

	i = 0;
	nb = ft_lenx(str);
	max = ft_max(ptf->width2, nb);
	while (i < (ptf->width2) - nb)
	{
		(ft_putchar('0', ptf));
		i++;
	}
	if ((str == 0) && (ptf->width2 == 0) && (ptf->width1 != 0))
		ft_putchar(' ', ptf);
	else if ((str != 0) || (ptf->width2 != 0))
		ft_putnbr_x(str, ptf);
	i = 0;
	while (i < (ptf->width1) - max)
		i = ft_increase(ptf, i);
}

void			ft_printf_x_2(t_ptf *ptf, unsigned long str)
{
	int i;
	int max;
	int nb;

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
		ft_putnbr_x(str, ptf);
}
