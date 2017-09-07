/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_links				*create_t_links(t_links *in, t_room *room)
{
	t_links			*link;
	t_links			*copy;

	link = (t_links*)malloc(sizeof(t_links));
	link->room_name = room->name;
	link->link = room;
	link->next = NULL;
	if (in)
	{
		copy = in;
		while (copy->next)
			copy = copy->next;
		copy->next = link;
	}
	return (link);
}

t_ways				*create_t_ways(void)
{
	t_ways			*way;

	way = (t_ways *)malloc(sizeof(t_ways));
	way->id = 0;
	way->total_links = 0;
	way->ants = 0;
	way->links = (t_read *)malloc(sizeof(t_read));
	way->links->next = NULL;
	way->links->str = NULL;
	way->next = NULL;
	return (way);
}

t_room				*create_t_room(void)
{
	t_room			*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = NULL;
	room->value = 0;
	room->links_in_room = 0;
	room->y = 0;
	room->x = 0;
	room->ant = 0;
	room->links = NULL;
	room->next = NULL;
	return (room);
}

t_all_info			*create_t_all_info(void)
{
	t_all_info		*info;

	info = (t_all_info*)malloc(sizeof(t_all_info));
	info->start = NULL;
	info->wait_start = 0;
	info->end = NULL;
	info->wait_end = 0;
	info->error = 0;
	info->total_start_ants = 0;
	info->current_ant = 1;
	info->total_ways = 0;
	info->total_value = 0;
	info->color_ways = 0;
	info->rooms = NULL;
	info->ways = NULL;
	info->color_ant = 0;
	return (info);
}

t_read				*create_t_read(void)
{
	t_read			*read;

	read = (t_read *)malloc(sizeof(t_read));
	read->next = NULL;
	read->str = NULL;
	return (read);
}
