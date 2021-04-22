/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, t_ptf *ptf)
{
	ptf->ret++;
	write(1, &c, 1);
}

void	ft_putchar_long(char *str, int len, t_ptf *ptf)
{
	int		i;
	char	c;

	i = 0;
	ptf->ret = ptf->ret + len;
	while (i < len && str[i])
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}

int		my_printf_i(t_ptf *ptf)
{
	int str;

	str = va_arg(*ptf->val, int);
	if (ptf->moins != 0)
		ft_printf_i_1(ptf, str);
	else if (ptf->moins == 0)
		ft_printf_i_2(ptf, str);
	return (0);
}

void	ft_printf_i_1(t_ptf *ptf, int str)
{
	int		i;
	int		max;
	long	nb;

	i = 0;
	nb = ft_lennum(str);
	max = ft_max(ptf->width2, nb);
	if (str < 0)
		ft_putchar('-', ptf);
	while (i < (ptf->width2) - nb)
	{
		ft_putchar('0', ptf);
		i++;
	}
	i = (str < 0 ? 1 : 0);
	nb = ft_abs(str);
	if ((nb == 0) && (ptf->width2 == 0) && (ptf->width1 != 0))
		ft_putchar(' ', ptf);
	else if ((nb != 0) || (ptf->width2 != 0))
		ft_putnbr(nb, ptf);
	while (i < (ptf->width1) - max)
		i = ft_increase(ptf, i);
}

void	ft_printf_i_2(t_ptf *ptf, int str)
{
	int		i;
	long	max;
	int		nb;

	i = (str < 0 ? 1 : 0);
	nb = ft_lennum(str);
	max = ft_max(ptf->width2, nb);
	if ((str < 0) && (ptf->zero == 1))
		ft_putchar('-', ptf);
	while (i < (ptf->width1) - max)
		i = ft_increase(ptf, i);
	i = 0;
	if ((str < 0) && (ptf->zero == 0))
		ft_putchar('-', ptf);
	max = ft_abs(str);
	while (i < (ptf->width2) - nb)
	{
		ft_putchar('0', ptf);
		i++;
	}
	if ((max == 0) && (ptf->width2 == 0) && (ptf->width1 != 0))
		ft_putchar(' ', ptf);
	else if ((max != 0) || (ptf->width2 != 0))
		ft_putnbr(max, ptf);
}
