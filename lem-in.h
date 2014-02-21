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

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list		t_list;
typedef struct s_house		t_house;
typedef struct s_room		t_room;
typedef struct s_tube		t_tube;
typedef struct s_ant		t_ant;
typedef struct s_route		t_route;
typedef struct s_route_el	t_route_el;

struct			s_ant
{
	int			id;
	char		*name;
	t_list		*route;
	t_ant		*next;
};

struct			s_route_el
{
	char		*value;
	int			occupied;
	t_route_el	*next;
	t_route_el	*prev;
};

struct			s_route
{
	t_route_el		*first;
	t_route_el		*last;
};

struct			s_list
{
	char		*value;
	t_list		*next;
};

struct			s_house
{
	int			ants;
	int			arrived;
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

void	ft_error(int error);
void	get_config(t_list **config);
t_list	*lst_add(t_list *list, t_list *new);
t_list	*lst_new(char *value);
void	ft_lstrev(t_list **list);
void	print_list(t_list *list);
void	init_antshouse(t_house **house, t_list *config);
void	init_ants(t_house *house, t_list *config);
int		check_line(t_list *config);
t_list	*init_rooms(t_house *house, t_list *config);
int		check_start_end(char *str, t_house *house);
int		check_room_exist(t_room *room, char *str);
t_room	*rm_add(t_room *list, t_room *new);
t_room	*rm_new(char *value, int mode);
int		init_tubes(t_room *room, t_list *config);
int		check_tube(t_room *room, char *str);
void	link_rooms(t_room **room, char *str);
t_room	*add_room_link(t_room *room, char *name);
t_list	*calc_path(t_room *room);
t_room	*find_start(t_room *room);
int		swipe_start(t_room **room);
int		swipe(int i, t_list *links, t_room *room);
t_list	*shortest_route(t_room *room);
t_room	*find_next_node(int weight, t_room *room, t_list *name);
t_route	*make_route(t_list *list);
t_route	*add_route(t_route *route, char *str);
t_route	*route_loop(t_route *list);
void	march_of_ants(t_list *ant_route, t_house *house, t_route *route);
void	create_ant(t_ant **swarm, int id, t_list *simple_route);
void	start_march(t_ant *ants, t_house *house, t_route *list);
void	p(t_ant *tmp, t_route_el **route, t_house **house, t_ant **ants);

#endif

