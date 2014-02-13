/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <mmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:45:07 by mmaudet           #+#    #+#             */
/*   Updated: 2013/12/01 14:17:22 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			i;
	const unsigned char		*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		if (ptr[i] == c)
			return ((char*)(&ptr[i]));
		i++;
	}
	return (0);
}
