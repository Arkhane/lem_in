/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:58:51 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/13 14:58:52 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>

t_room		*rm_new(char *value, int mode)
{
	t_room		*new;
	int			i;

	i = 0;
	while (value[i] > 32 && value[i] < 127)
		i++;
	value = ft_strsub(value, 0, i);
	new = malloc(sizeof(t_room));
	new->next = NULL;
	new->name = value;
	if (mode == 1)
		new->start = 1;
	if (mode == 2)
		new->end = 1;
	return (new);
}

t_room		*rm_add(t_room *list, t_room *new)
{
	t_room		*tmp;

	tmp = list;
	if (list)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		list = new;
	return (list);
}

t_room		*add_room_link(t_room *room, char *name)
{
	t_list		*new;
	t_list		*tmp;

	new = malloc(sizeof(t_list));
	new->next = NULL;
	new->value = name;
	tmp = room->links;
	if (room->links)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		room->links = new;
	return (room);
}
