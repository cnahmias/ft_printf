/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_num1(t_ptf *ptf, char *src)
{
	int i;
	int num;

	i = ptf->flag;
	num = src[i] - 48;
	i++;
	while (i < ptf->num1)
	{
		num = 10 * num + src[i] - 48;
		i++;
	}
	if (ptf->star1 == 0)
		ptf->width1 = num;
}

void	ft_num2(t_ptf *ptf, char *src)
{
	int i;
	int num;

	i = ptf->precis;
	num = src[i] - 48;
	i++;
	while (i < ptf->num2)
	{
		num = 10 * num + src[i] - 48;
		i++;
	}
	if (ptf->star2 == 0)
		ptf->width2 = num;
}

void	ft_precis(t_ptf *ptf)
{
	if ((ptf->precis - ptf->num1 == 1) && (ptf->letter != 8)
		&& ((ptf->star2 == 0) || (ptf->width2 >= 0)))
	{
		ptf->zero = 0;
		ptf->point = 1;
	}
	if ((ptf->width2 >= 0) && (ptf->letter != 8))
		ptf->zero = 0;
	if ((ptf->star2 == 1) && (ptf->width2 < 0))
		ptf->point = 0;
}

void	my_printf_null(char *src, t_ptf *ptf)
{
	int i;

	i = ptf->start - 1;
	while (i < ptf->end)
	{
		ft_putchar(src[i], ptf);
		i++;
	}
}

int		find_index(char *tab, char element)
{
	int index;

	index = 0;
	while (tab[index] != 0)
	{
		if (tab[index] == element)
			return (index);
		index++;
	}
	return (-1);
}
