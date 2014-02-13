/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <mmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:54:11 by mmaudet           #+#    #+#             */
/*   Updated: 2013/11/26 17:19:46 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dlen;

	i = 0;
	dlen = ft_strlen(dst);
	if (size > dlen)
	{
		while (src[i] != '\0' && i + dlen < size - 1)
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = '\0';
		return (dlen + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
