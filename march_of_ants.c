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

void		start_march(t_ant *ants, t_house *house)
{
	t_ant		*tmp;

	while (house->arrived > house->ants)
	{
		tmp = ants;
		while (tmp)
		{
			while (ft_strcmp(tmp->route->value, route->value) != 0)
				route = route->next;
			if (tmp->route && route->occupied == 0)
			{
				if (route->prev)
					route->prev->occupied = 0;
				ft_putstr(tmp->name);
				ft_putstr("-");
				ft_putstr(tmp->route->value);
				route->occupied = 1;
				tmp->route = tmp->route->next;
			}
			tmp = tmp->next;
			if (tmp)
				ft_putchar(" ");
		}
	}

}

void		create_ant(t_ant **swarm, int id, t_list *route)
{
	t_ant		*new;
	t_ant		*tmp;

	new = malloc(sizeof(t_ant));
	new->id = id;
	new->route = route;
	new->name = ft_strjoin("L", ft_atoi(id));
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

void		march_of_ants(t_list *route, t_house *house)
{
	int			id;
	t_ant		*swarm;

	id = 0;
	swarm = NULL;
	while (house->ants - id > 0)
	{
		create_ant(&swarm, id, route);
		id++;
	}
	start_march(swarm, house);
}
