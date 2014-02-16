/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:11:07 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/14 18:11:08 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>
/*
int			path_to_end(t_room **path, t_room **room)
{
	t_room		*tpath;
	t_room		*troom;
	char		*togo;

	tpath = *path;
	troom = *room;
	while (tpath->next)
		tpath = tpath->next;
	togo = ft_strdup(tpath->links->value);
	while (troom || ft_strcmp(togo, troom->name) != 0)
		troom = troom->next;
	if (troom->visited == 0)
	{
		troom->visited = 1;
		tpath = rm_add(tpath, troom);
		ft_putstr("La room suivante a ete ajoutee au chemin : ");
		ft_putendl(troom->name);
	}
	if (troom->end == 1)
		return (1);
	return (0);
}
*/
t_room		*find_end(t_room *room)
{
	t_room		*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->end == 1)
			return (tmp);
		tmp = tmp->next;
	}
	ft_error(3);
	return (NULL);
}

t_room		*find_start(t_room *room)
{
	t_room		*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->start == 1)
			return (tmp);
		tmp = tmp->next;
	}
	ft_error(3);
	return (NULL);
}

void		swipe(int i, t_list *links, t_room *room)
{
	t_room		*tmp;

	while (links)
	{
		tmp = room;
		while (tmp && ft_strcmp(tmp->name, links->value) != 0)
			tmp = tmp->next;
		if (tmp->weight == 0)
			tmp->weight = i;
		links = links->next;
	}
}

int			swipe_start(t_room **room)
{
	int			ret;
	t_room		*tmp;

	ret = 0;
	tmp = (*room);

	while (tmp)
	{
		if (tmp->weight == 0)
			ret = 1;
		if (tmp->weight != 0)
			swipe(tmp->weight + 1, tmp->links, *room);
		tmp = tmp->next;
	}
	return (ret);
}

t_room		*calc_path(t_room *room)
{
	t_room		*start;
	t_room		*end;

	start = find_start(room);
	end = find_end(room);
/*	ft_putstr("La room de depart est la room ");
	ft_putendl(path->name);
	ft_putstr("La room de sortie est la room ");
	ft_putendl(end->name);*/
	start->weight = 1;
	while (swipe_start(&room) != 0)
		;
/*	while (room)
	{
		ft_putnbr(room->weight);
		ft_putendl(room->name);
		room = room->next;
	}
*/
	return (end);
}
