/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:56:25 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/16 17:56:28 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>

void		print_route(t_list *route)
{
	while (route)
	{
		ft_putendl(route->value);
		route = route->next;
	}
}

void		ft_lstrev(t_list **list)
{
	t_list	*end;
	t_list	*start;
	t_list	*tmp;

	if (list == 0 || *list == 0)
		return ;
	end = *list;
	start = end;
	while (end->next != 0)
	{
		tmp = end->next;
		end->next = tmp->next;
		tmp->next = start;
		start = tmp;
	}
	*list = start;
}

t_room		*find_next_node(int weight, t_room *room, t_list *name)
{
	t_room		*tmp;
	int			found;

	found = 0;
	while (found == 0)
	{
		tmp = room;
		while (tmp && tmp->weight != weight)
			tmp = tmp->next;
		if (tmp->weight == weight)
			found = 1;
		else
			name = name->next;
	}
	return (tmp);
}

t_list		*add_to_route(t_list **route, t_room *tmp)
{
	t_list		*new;

	new = malloc(sizeof(t_list));
	new->next = NULL;
	new->value = ft_strdup(tmp->name);
	if (*route)
		new->next = *route;
	else
		*route = new;
	return (new);
}

t_list		*shortest_route(t_room *room)
{
	t_room		*tmp;
	int			weight;
	t_list		*route;
	t_list		*name;

	tmp = room;
	route = NULL;
	while (tmp && tmp->end == 0)
		tmp = tmp->next;
	if (tmp->weight == 0)
		ft_error(7);
	weight = tmp->weight;
	route = lst_add(route, lst_new(tmp->name));
	while (weight-- > 1)
	{
		name = tmp->links;
		tmp = room;
		tmp = find_next_node(weight, room, name);
		route = lst_add(route, lst_new(tmp->name));
	}
	return (route);
}
