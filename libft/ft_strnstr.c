/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <mmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 12:03:40 by mmaudet           #+#    #+#             */
/*   Updated: 2013/12/01 21:09:42 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s2)
		return ((char*)s1);
	while (s1[i] != '\0' && s2[j] != '\0' && i < size)
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	if (s2[j] == '\0')
		return ((char *) s1 + i - j);
	return (0);
}
