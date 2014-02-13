/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <mmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:44:05 by mmaudet           #+#    #+#             */
/*   Updated: 2013/11/26 11:47:24 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	i;

	if (s == 0)
		return (0);
	res = ft_strnew(n);
	if (res == 0)
		return (0);
	i = 0;
	while (i < n && s[i] != 0)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
