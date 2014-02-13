/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <mmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:51:35 by mmaudet           #+#    #+#             */
/*   Updated: 2014/01/10 15:21:52 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ilen(int nb);
static char		*ft_itoa_err(int n);

char			*ft_itoa(int n)
{
	int		i;
	int		ilen;
	char	*str;

	i = 0;
	ilen = ft_ilen(n);
	if (n == 0 || n == -2147483648)
		return (ft_itoa_err(n));
	str = malloc(sizeof(char) * ilen + 1);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	str[i + ilen] = '\0';
	while (ilen > 0)
	{
		str[i + ilen - 1] = (n % 10) + 48;
		n = n / 10;
		ilen--;
	}
	return (str);
}

static int		ft_ilen(int nb)
{
	int		n;

	n = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		n++;
	}
	return (n);
}

static char		*ft_itoa_err(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	else
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
}
