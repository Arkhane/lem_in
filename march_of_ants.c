/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march_of_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 18:19:58 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/17 18:20:00 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>

void	p(t_ant *tmp, t_route_el **route, t_house **house, t_ant **ants)
{
	if (tmp->route)
	{
		while (ft_strcmp(tmp->route->value, (*route)->value) != 0)
			*route = (*route)->next;
	}
	if (tmp->route && (*route)->occupied == 0)
	{
		(*route)->prev->occupied = 0;
		ft_putstr(tmp->name);
		ft_putstr("-");
		ft_putstr(tmp->route->value);
		ft_putchar(' ');
		(*route)->occupied = 1;
		if (tmp->route->next)
			tmp->route = tmp->route->next;
		else
		{
			(*house)->arrived++;
			*ants = (*ants)->next;
			(*route)->occupied = 0;
		}
	}
}

void	start_march(t_ant *ants, t_house *house, t_route *list)
{
	t_ant		*tmp;
	t_route_el	*route;

	while (house->arrived < house->ants)
	{
		tmp = ants;
		while (tmp)
		{
			route = list->first;
			p(tmp, &route, &house, &ants);
			tmp = tmp->next;
		}
		ft_putchar('\n');
	}
}

void	create_ant(t_ant **swarm, int id, t_list *simple_route)
{
	t_ant		*new;
	t_ant		*tmp;

	new = malloc(sizeof(t_ant));
	new->id = id + 1;
	simple_route = simple_route->next;
	new->route = simple_route;
	new->name = ft_strjoin("L", ft_itoa(id + 1));
	tmp = *swarm;
	if (*swarm)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*swarm = new;
}

void	march_of_ants(t_list *ant_route, t_house *house, t_route *route)
{
	int			id;
	t_ant		*swarm;

	id = 0;
	swarm = NULL;
	while (house->ants - id > 0)
	{
		create_ant(&swarm, id, ant_route);
		id++;
	}
	start_march(swarm, house, route);
}

