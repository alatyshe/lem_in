/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

static int			last_room_havent_ways(t_room *end_room)
{
	t_links			*links;

	links = end_room->links;
	if (links)
	{
		while (links)
		{
			if (links->link->value > 0)
				return (0);
			links = links->next;
		}
	}
	return (1);
}

static int			find_rooms_by_values(t_all_info *info, int value)
{
	t_room			*copy;
	int				counter;

	copy = info->rooms;
	counter = 0;
	if (copy)
	{
		while (copy)
		{
			if (copy->value == value && ft_strcmp(info->end, copy->name))
				counter += fill_room_value(copy, value + 1);
			copy = copy->next;
		}
	}
	if (counter == 0
		&& last_room_havent_ways(find_room_by_str(info, info->end)))
		info->error = 1;
	return (counter);
}

static int			save_one_way(t_ways *way, t_room *start,
	t_room *last, int next_value)
{
	t_room			*next_room;
	t_read			*last_link;

	last_link = get_last_link(way->links);
	last_link->str = ft_strdup(last->name);
	if (ft_strcmp(start->name, last->name) != SAME)
	{
		last->value = -2147483648;
		if (!(next_room = find_room_by_value(last->links, next_value)))
			return (0);
		way->total_links++;
		last_link->next = create_t_read();
		if (save_one_way(way, start, next_room, next_value - 1) == 0)
		{
			last->value = 0;
			return (0);
		}
		if (ft_strcmp(start->name, next_room->name) != SAME)
			next_room->value = -2147483648;
		return (1);
	}
	last_link->next = NULL;
	return (1);
}

void				save_all_ways(t_all_info *info, t_room *start, t_room *end)
{
	int				counter;
	t_ways			*copy_ways;

	counter = 0;
	while (counter < info->total_ways)
	{
		copy_ways = create_t_ways();
		if (save_one_way(copy_ways, start, end,
			find_room_biggest_value(end->links)))
		{
			copy_ways->next = info->ways;
			copy_ways->id = info->total_ways - counter + 1;
			info->ways = copy_ways;
		}
		else
		{
			free_links(copy_ways->links);
			free(copy_ways);
			info->total_ways--;
		}
		counter++;
	}
}

void				ways(t_all_info *info)
{
	int				detector;
	int				counter;
	t_room			*start;
	t_room			*end;

	detector = 1;
	counter = 2;
	start = find_room_by_str(info, info->start);
	end = find_room_by_str(info, info->end);
	start->value = 1;
	fill_room_value(start, 2);
	while (last_room_value_empty(info, end) && info->error == 0 && detector > 0)
		detector = find_rooms_by_values(info, counter++);
	if (info->error == 1)
		return ;
	if (start->links_in_room > end->links_in_room)
		info->total_ways = end->links_in_room;
	else
		info->total_ways = start->links_in_room;
	save_all_ways(info, start, end);
}
