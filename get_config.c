/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:11:56 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/11 15:11:57 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>

void		print_links(t_room *room)
{
	t_room		*tmp;

	tmp = room;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putstr("   ...   ");
		while (tmp->links)
		{
			ft_putstr(tmp->links->value);
			ft_putstr(" - ");
			tmp->links = tmp->links->next;
		}
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void		print_list(t_list *list)
{
	while (list)
	{
		if (list->value)
			ft_putstr(list->value);
		ft_putstr("\n");
		list = list->next;
	}
}

void		print_rooms(t_house *house)
{
	t_room		*tmp;

	tmp = house->room;
	ft_putstr("Il y a ");
	ft_putnbr(house->ants);
	ft_putendl(" fourmis dans la fourmiliere !");
	while (tmp->next)
	{
		ft_putendl(tmp->name);
		if (tmp->start == 1)
			ft_putendl("C'est l'entree !");
		if (tmp->end == 1)
			ft_putendl("C'est la sortie !");
		tmp = tmp->next;
	}
	ft_putendl(tmp->name);
	if (tmp->end == 1)
		ft_putendl("C'est la sortie !");
}

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

t_list		*lst_new(char *value)
{
	t_list		*new;

	new = malloc(sizeof(t_list));
	new->next = NULL;
	new->value = value;
	return (new);
}

t_list		*lst_add(t_list *list, t_list *new)
{
	t_list		*tmp;

	tmp = list;
	if (list)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		list = new;
	return (list);
}

void		get_config(t_list **config)
{
	char		*line;
	int			ret;

	ret = 42;
	while (ret != 0) //ft_strncmp(line, "ok", 2) != 0)
	{
		ret = get_next_line(0, &line);
		*config = lst_add(*config, lst_new(line));
	}
}
