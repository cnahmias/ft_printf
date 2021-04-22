/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		my_printf_p(t_ptf *ptf)
{
	void *ptr;
	long nb;

	ptr = va_arg(*ptf->val, void*);
	nb = (long)ptr;
	if (ptf->moins != 0)
		ft_printf_p_1(ptf, nb);
	else
		ft_printf_p_2(ptf, nb);
	return (0);
}

void	ft_printf_p_1(t_ptf *ptf, long nb)
{
	long a;

	ft_putchar('0', ptf);
	ft_putchar('x', ptf);
	if ((ptf->width2 != 0) || (ptf->point != 1) || (nb != 0))
	{
		ft_putnbr_x(nb, ptf);
		a = ft_lenx(nb) + 2;
	}
	else
		a = 2;
	while (a < (ptf->width1))
	{
		ft_putchar(' ', ptf);
		a++;
	}
}

void	ft_printf_p_2(t_ptf *ptf, long nb)
{
	long a;

	a = 2;
	if ((ptf->width2 != 0) || (ptf->point != 1) || (nb != 0))
		a += ft_lenx(nb);
	while (a < (ptf->width1))
	{
		ft_putchar(' ', ptf);
		a++;
	}
	ft_putchar('0', ptf);
	ft_putchar('x', ptf);
	if ((ptf->width2 != 0) || (ptf->point != 1) || (nb != 0))
		ft_putnbr_x(nb, ptf);
}
