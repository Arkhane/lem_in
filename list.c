/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 12:42:02 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/20 12:42:03 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <libft.h>

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
