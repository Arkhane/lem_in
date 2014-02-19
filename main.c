/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:11:56 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/11 15:11:57 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>

int			check_line(t_list *config)
{
	int			i;

	i = 0;
	if (config->value)
	{
		while (config->value[i] != '\0')
		{
			if (config->value[i] == 'L')
				ft_error(1);
			if (config->value[i] == '-')
				return (1);
			i++;
		}
	}
	return (0);
}

int			check_start_end(char *str, t_house *house)
{

	if (!str)
		(ft_error(3));
	if (ft_strncmp(str, "##start", 7) == 0)
	{
		if (house->has_start == 1)
			ft_error(3);
		house->has_start = 1;
		return (1);
	}
	if (ft_strncmp(str, "##end", 5) == 0)
	{
		if (house->has_end == 1)
			ft_error(3);
		house->has_end = 1;
		return (2);
	}
	if (str[0] == 35)
		return (3);
	return (0);
}

void		link_rooms(t_room **room, char *str)
{
	char		*room1;
	char		*room2;
	int			i;

	i = 0;
	while (str[i] != '-')
		i++;
	room1 = ft_strsub(str, 0, i);
	room2 = ft_strsub(str, i + 1, ft_strlen(str));
	while ((*room) != NULL)
	{
		if (ft_strcmp((*room)->name, room1) == 0)
			*room = add_room_link(*room, room2);
		if (ft_strcmp((*room)->name, room2) == 0)
			*room = add_room_link(*room, room1);
		*room = (*room)->next;
	}
}

int			check_tube(t_room *room, char *str)
{
	char		*room1;
	char		*room2;
	int			i;
	int			found;

	i = 0;
	found = 0;


	while (str[i] != '-')
		i++;
	room1 = ft_strsub(str, 0, i);
	room2 = ft_strsub(str, i + 1, ft_strlen(str));
	if (ft_strcmp(room1, room2) == 0)
		ft_error(6);
	while (room != NULL)
	{
		if (ft_strcmp(room->name, room1) == 0
			|| ft_strcmp(room->name, room2) == 0)
			found++;
		room = room->next;
	}
	if (found >= 2)
		return (1);
	return (0);
}

void		init_tubes(t_room *room, t_list *config)
{
	t_room		*tmp;

	tmp = room;
	if (check_tube(tmp, config->value) == 0)
		ft_error(4);
	link_rooms(&tmp, config->value);
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
		ft_error(0);
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
//	ft_putendl("----- PARSING ROOMS -----");
//	print_rooms(*house);
//	ft_putendl("----- tests tubes -----");
	if ((*house)->has_end == 0 || (*house)->has_start == 0)
		ft_error(3);
	while (check_line(config) == 1)
	{
		init_tubes((*house)->room, config);
		config = config->next;
	}
//	print_links((*house)->room);
}

void		ft_error(int error)
{
	if (error == 0)
		ft_putendl("Error : invalid Ants");
	if (error == 1)
		ft_putendl("Error : 'L' in parameters");
	if (error == 2)
		ft_putendl("Error : Empty list");
	if (error == 3)
		ft_putendl("Error : Start/End redefined or inexistant");
	if (error == 4)
		ft_putendl("Error : Can't create tube from invalid room name");
	if (error == 5)
		ft_putendl("Error : Room already exists");
	if (error == 6)
		ft_putendl("Error : Tube connecting room to itself");
	if (error == 7)
		ft_putendl("Error : Exit not connected to Entry");
	exit(0);
}

int			main(void)
{
	t_list		*config;
	t_house		*house;
	t_list		*route;

	config = NULL;
	house = malloc(sizeof(t_house));
//	config = malloc(sizeof(t_list));
	get_config(&config);
//	ft_putendl("----- LISTE -----");
	print_list(config);
	init_antshouse(&house, config);
//	print_rooms(house);
	route = calc_path(house->room);
	march_of_ants(route, house);
	return (0);
}
