/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaudet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:44:39 by mmaudet           #+#    #+#             */
/*   Updated: 2014/02/11 15:44:40 by mmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list	t_list;
typedef struct s_house	t_house;
typedef struct s_room	t_room;
typedef struct s_tube	t_tube;

struct			s_list
{
	char		*value;
	t_list		*next;
};

struct			s_house
{
	int			ants;
	t_room		*room;
	t_tube		*tube;
	int			has_start;
	int			has_end;
};

struct			s_room
{
	char		*name;
	int			start;
	int			end;
	int			visited;
	int			weight;
	t_list		*links;
	t_room		*next;
};

struct			s_tube
{
	char		*entry1;
	char		*entry2;
	t_tube		*next;
};

void		get_config(t_list **config);
t_list		*lst_add(t_list *list, t_list *new);
t_list		*lst_new(char *value);
void		ft_error(int error);
t_room		*rm_add(t_room *list, t_room *new);
t_room		*rm_new(char *value, int mode);
int			check_line(t_list *config);
void		print_rooms(t_house *house);
t_room		*add_room_link(t_room *room, char *name);
t_room		*calc_path(t_room *room);
t_room		*find_start(t_room *room);
t_room		*find_end(t_room *room);

void		print_list(t_list *list);
void		print_links(t_room *room);
#endif

