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

void		get_config(t_list **config)
{
	char		*line;
	int			ret;

	ret = 42;
	while (ret != 0)
	{
		ret = get_next_line(0, &line);
		*config = lst_add(*config, lst_new(line));
	}
}

void		ft_error(int error)
{
	if (error == 0)
		ft_putendl_fd("ERROR : invalid Ants", 2);
	if (error == 1)
		ft_putendl_fd("ERROR : 'L' in room parameters", 2);
	if (error == 2)
		ft_putendl_fd("ERROR : Empty list", 2);
	if (error == 3)
		ft_putendl_fd("ERROR : Start/End redefined or inexistant", 2);
	if (error == 5)
		ft_putendl_fd("ERROR : Room already exists", 2);
	if (error == 7)
		ft_putendl_fd("ERROR : Exit not connected to Entry", 2);
	exit(0);
}

int			main(void)
{
	t_list		*config;
	t_house		*house;
	t_list		*simple_route;
	t_route		*route;

	config = NULL;
	house = malloc(sizeof(t_house));
	get_config(&config);
	print_list(config);
	init_antshouse(&house, config);
	simple_route = calc_path(house->room);
	route = make_route(simple_route);
	march_of_ants(simple_route, house, route);
	return (0);
}
