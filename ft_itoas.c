/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_max(int n1, int n2)
{
	int max;

	if (n1 > n2)
		max = n1;
	else
		max = n2;
	return (max);
}

int		ft_min(int n1, int n2)
{
	int min;

	if (n1 > n2)
		min = n2;
	else
		min = n1;
	return (min);
}

void	ft_putnbr_x(unsigned long nb, t_ptf *ptf)
{
	char *alpha;

	alpha = "abcdef";
	if (nb >= 16)
	{
		ft_putnbr_x(nb / 16, ptf);
		ft_putnbr_x(nb % 16, ptf);
	}
	else if (nb >= 10)
		ft_putchar(alpha[nb - 10], ptf);
	else
		ft_putchar(nb + '0', ptf);
}

void	ft_putnbr_xm(unsigned long nb, t_ptf *ptf)
{
	char *alpha;

	alpha = "ABCDEF";
	if (nb >= 16)
	{
		ft_putnbr_xm(nb / 16, ptf);
		ft_putnbr_xm(nb % 16, ptf);
	}
	else if (nb >= 10)
		ft_putchar(alpha[nb - 10], ptf);
	else
		ft_putchar(nb + '0', ptf);
}

void	ft_putnbr(long nb, t_ptf *ptf)
{
	if (nb < 0)
	{
		ft_putchar('-', ptf);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, ptf);
		ft_putnbr(nb % 10, ptf);
	}
	else
		ft_putchar(nb + '0', ptf);
}
