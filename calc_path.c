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

int			swipe(int i, t_list *links, t_room *room)
{
	t_room		*tmp;
	int			flag;

	flag = 0;
	while (links)
	{
		tmp = room;
		while (tmp && ft_strcmp(tmp->name, links->value) != 0)
			tmp = tmp->next;
		if (tmp->weight == 0)
		{
			tmp->weight = i;
			flag = 1;
		}
		links = links->next;
	}
	return (flag);
}

int			swipe_start(t_room **room)
{
	t_room		*tmp;
	int			flag;

	tmp = (*room);
	while (tmp)
	{
		if (tmp->weight != 0)
			flag = swipe(tmp->weight + 1, tmp->links, *room);
		tmp = tmp->next;
	}
	return (flag);
}

t_list		*calc_path(t_room *room)
{
	t_room		*start;
	t_list		*simple_route;

	start = find_start(room);
	start->weight = 1;
	while (swipe_start(&room) != 0)
		;
	simple_route = shortest_route(room);
	ft_lstrev(&simple_route);
	return (simple_route);
}
