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
//	ft_putstr("La room nommee ");
//	ft_putstr(room->name);
//	ft_putstr(" est maintenant linkee a la room ");
//	ft_putendl(room->links->value);
	return (room);
}
