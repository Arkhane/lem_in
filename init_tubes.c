/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 12:34:15 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/20 12:34:16 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>

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
		return (0);
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

int			init_tubes(t_room *room, t_list *config)
{
	t_room		*tmp;

	tmp = room;
	if (check_tube(tmp, config->value) == 0)
	{
		ft_putendl_fd("Can't create tube from invalid or same room name", 2);
		ft_putendl_fd("Trying to solve the maze with previous data", 2);
		return (0);
	}
	link_rooms(&tmp, config->value);
	return (1);
}
