/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ss1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		my_printf_c(t_ptf *ptf)
{
	char	c;
	int		i;

	i = 0;
	c = va_arg(*ptf->val, int);
	if (ptf->moins == 0)
	{
		while (i < ptf->width1 - 1)
		{
			ft_putchar(' ', ptf);
			i++;
		}
		ft_putchar(c, ptf);
	}
	else
	{
		ft_putchar(c, ptf);
		while (i < ptf->width1 - 1)
		{
			ft_putchar(' ', ptf);
			i++;
		}
	}
	return (0);
}

int		my_printf_s(t_ptf *ptf)
{
	char *str;

	str = va_arg(*ptf->val, char *);
	if (!str)
		str = "(null)";
	if (ptf->point != 0 && ptf->moins != 0)
		ft_printf_s_1(ptf, str);
	else if (ptf->point == 0 && ptf->moins != 0)
		ft_printf_s_2(ptf, str);
	else if (ptf->point == 0 && ptf->moins == 0)
		ft_printf_s_3(ptf, str);
	else if (ptf->point != 0 && ptf->moins == 0)
		ft_printf_s_4(ptf, str);
	return (0);
}

void	ft_printf_s_1(t_ptf *ptf, char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while ((i < ptf->width2) && str[i])
	{
		ft_putchar(str[i], ptf);
		i++;
	}
	if (ptf->width2 == -1)
	{
		while (str[i])
		{
			ft_putchar(str[i], ptf);
			i++;
		}
	}
	while (i < ptf->width1)
	{
		ft_putchar(' ', ptf);
		i++;
	}
}

void	ft_printf_s_2(t_ptf *ptf, char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	ft_putchar_long(str, len, ptf);
	if (len < (ptf->width1))
	{
		while (i < (ptf->width1) - len)
		{
			ft_putchar(' ', ptf);
			i++;
		}
	}
}
