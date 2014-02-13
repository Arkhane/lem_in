/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <mmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:43:59 by mmaudet           #+#    #+#             */
/*   Updated: 2013/11/26 17:29:15 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char			*ptr1;
	const unsigned char		*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	if (n == 0)
		return (s1);
	if (ptr1 < ptr2)
		return (ft_memcpy(s1, s2, n));
	ptr1 += n - 1;
	ptr2 += n - 1;
	while (n > 0)
	{
		*ptr1 = *ptr2;
		ptr1--;
		ptr2--;
		n--;
	}
	return (s1);
}
