/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 12:48:38 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/20 12:48:39 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>

t_route		*route_loop(t_route *list)
{
	t_route_el	*tmp;

	tmp = list->first;
	tmp->prev = list->last;
	tmp = list->last;
	tmp->next = list->first;
	return (list);
}

t_route		*add_route(t_route *route, char *str)
{
	t_route_el		*e;

	e = malloc(sizeof(t_route_el));
	e->value = str;
	e->next = NULL;
	if (route->first == NULL)
	{
		e->prev = NULL;
		route->first = e;
	}
	else
	{
		route->last->next = e;
		e->prev = route->last;
	}
	route->last = e;
	return (route);
}

t_route		*make_route(t_list *list)
{
	t_route		*route;

	route = malloc(sizeof(t_route));
	route->first = NULL;
	route->last = NULL;
	while (list)
	{
		route = add_route(route, list->value);
		list = list->next;
	}
	route_loop(route);
	return (route);
}
