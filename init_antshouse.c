/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_antshouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 12:32:29 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/20 12:32:30 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>

int			check_line(t_list *config)
{
	int			i;
	int			l_found;

	i = 0;
	l_found = 0;
	if (config->value)
	{
		while (config->value[i] != '\0')
		{
			if (config->value[i] == 'L')
				l_found = 1;
			if (config->value[i] == '-' && l_found == 0)
				return (1);
			if (config->value[i] == '-' && l_found == 1)
				return (0);
			i++;
		}
		if (l_found == 1)
			ft_error(1);
	}
	return (0);
}

int			check_room_exist(t_room *room, char *str)
{
	t_room		*tmp;

	tmp = room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_list		*init_rooms(t_house *house, t_list *config)
{
	int			check;

	check = check_start_end(config->value, &*house);
	if (check == 1 || check == 2)
	{
		config = config->next;
		if (check_room_exist(house->room, config->value) == 1)
			ft_error(5);
		if (check == 1)
			house->room = rm_add(house->room, rm_new(config->value, 1));
		if (check == 2)
			house->room = rm_add(house->room, rm_new(config->value, 2));
		return (config);
	}
	if (check == 3)
		return (config);
	if (check_room_exist(house->room, config->value) == 1)
			ft_error(5);
	house->room = rm_add(house->room, rm_new(config->value, 0));
	return (config);
}

void		init_ants(t_house *house, t_list *config)
{
	int			i;

	i = 0;
	if (!config->value)
		ft_error(2);
	while (config->value[i])
	{
		if (config->value[i] < 48 || config->value[i] > 57)
			ft_error(0);
		i++;
	}
	house->ants = ft_atoi(config->value);
}

void		init_antshouse(t_house **house, t_list *config)
{
	init_ants(*house, config);
	config = config->next;
	while (check_line(config) == 0)
	{
		config = init_rooms(*house, config);
		config = config->next;
	}
	if ((*house)->has_end == 0 || (*house)->has_start == 0)
		ft_error(3);
	while (check_line(config) == 1)
	{
		if (init_tubes((*house)->room, config) == 0)
			break ;
		config = config->next;
	}
}
