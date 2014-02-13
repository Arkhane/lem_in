/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <mmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:48:29 by mmaudet           #+#    #+#             */
/*   Updated: 2013/11/26 13:48:25 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static int	wordlen(const char *s, char c);
static char	*next_word(const char *s, char c);

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;

	if (s == 0)
		return ((char **) 0);
	while (*s == c)
		s++;
	res = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (res == 0)
		return ((char **) 0);
	i = 0;
	while (s != 0 && *s != 0)
	{
		if ((res[i] = ft_strndup(s, wordlen(s, c))) == 0)
			return ((char **) 0);
		i++;
		s = next_word(s, c);
	}
	res[i] = 0;
	return (res);
}

int			count_words(char const *s, char c)
{
	int		count;
	int		sep;

	count = 0;
	sep = 1;
	while (*s != 0)
	{
		if (*s != c && sep == 1)
		{
			sep = 0;
			count++;
		}
		else if (*s == c && sep == 0)
			sep = 1;
		s++;
	}
	return (count);
}

int			wordlen(const char *s, char c)
{
	if (*s == c || *s == 0)
		return (0);
	else
		return (1 + wordlen(s + 1, c));
}

char		*next_word(const char *s, char c)
{
	while (*s != c && *s != 0)
		s++;
	if (*s == 0)
		return (0);
	while (*s == c)
		s++;
	if (*s == 0)
		return (0);
	else
		return ((char *) s);
}
