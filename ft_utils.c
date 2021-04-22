/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnahmias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by cnahmias          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by cnahmias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long	ft_abs(int i)
{
	long a;

	a = i;
	if (a < 0)
		a = -a;
	return (a);
}

int		ft_strlen(char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
		return ((int)0);
	while (src[i])
		i++;
	return (i);
}

int		ft_lennum(long i)
{
	int		len;
	long	nb;

	len = 0;
	nb = i;
	if (i == 0)
		return (1);
	if (i < 0)
		nb = -i;
	while (nb > 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

int		ft_lennum_abs(long i)
{
	int	len;

	len = ft_lennum(i);
	if (i < 0)
		len++;
	return (len);
}

bool	ft_isnum(char c)
{
	if ((c > 47) && (c < 58))
		return (true);
	else
		return (false);
}
