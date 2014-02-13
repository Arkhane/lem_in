/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <mmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 21:15:06 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/09 19:54:20 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int		check_buffer(char *buf, char **line)
{
	char	*p;
	char	*new;
	char	*tmp;

	if ((p = ft_strchr(buf, '\n')) != NULL)
	{
		if ((new = ft_strndup(buf, p - buf)) == NULL)
			return (-1);
		buf = ft_strcpy(buf, ++p);
	}
	else
	{
		if ((new = ft_strdup(buf)) == NULL)
			return (-1);
		ft_bzero(buf, BUFFSIZE);
	}
	tmp = *line;
	if ((*line = ft_strjoin(tmp, new)) == NULL)
		return (-1);
	ft_strdel(&tmp);
	ft_strdel(&new);
	if (p != NULL)
		return (1);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	static char		buf[BUFFSIZE + 1] = {0};

	if (BUFFSIZE <= 0 || (*line = ft_strnew(0)) == NULL)
		return (-1);
	if (ft_strlen(buf) != 0)
	{
		if ((ret = check_buffer(buf, line)) != 0)
			return (ret);
	}
	while ((ret = read(fd, buf, BUFFSIZE)) >= 0)
	{
		if (ret == 0)
		{
			if (ft_strlen(*line) > 0)
				return (1);
			ft_strdel(line);
			return (0);
		}
		buf[ret] = '\0';
		if ((ret = check_buffer(buf, line)) != 0)
			return (ret);
	}
	return (-1);
}

