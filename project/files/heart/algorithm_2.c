/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void				put_ant_second_room(t_all_info *info,
	t_ways *way, int *space)
{
	t_read			*copy_way;
	t_room			*before;
	t_room			*current;

	copy_way = way->links;
	current = find_room_by_str(info, copy_way->next->str);
	before = find_room_by_str(info, copy_way->str);
	put_ant_on_start_pos(info);
	while (copy_way->next != NULL)
	{
		copy_way = copy_way->next;
		if (copy_way->next && (before = current))
			current = find_room_by_str(info, copy_way->next->str);
	}
	if (before->ant == 0 && current->ant != 0)
	{
		if (info->color_ant == current->ant)
			move_ant(before, current, space, 1);
		else if (info->color_ways == 1)
			move_ant(before, current, space, way->id);
		else
			move_ant(before, current, space, 0);
		way->ants = 1;
	}
}

void				recursive_put_ants_second_room(t_all_info *info,
	t_ways *copy_ways, t_room *end, int *space)
{
	int				value;
	int				total_ants;
	int				before_value;

	total_ants = info->total_start_ants - info->current_ant;
	if (copy_ways)
	{
		before_value = info->total_value;
		value = info->total_value + copy_ways->total_links + 1;
		put_ant_second_room(info, copy_ways, space);
		put_ant_on_end_pos(end, copy_ways);
		info->total_value = copy_ways->total_links;
		if (copy_ways->next
			&& (value < total_ants
			|| copy_ways->next->total_links == copy_ways->total_links))
			recursive_put_ants_second_room(info, copy_ways->next, end, space);
	}
}
