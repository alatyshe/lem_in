/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void				move_ant(t_room *before, t_room *current,
	int *space, int color)
{
	if (color > 0 && color <= 6)
		ft_printf("\x1b[3%dm", color);
	if (*space == 1)
		ft_printf(" ");
	ft_printf("L%d-%s%s", current->ant, before->name, RESET);
	*space = 1;
	before->ant = current->ant;
	current->ant = 0;
}

void				find_ant_and_muve(t_all_info *info, t_ways *way,
	size_t ant, int *space)
{
	t_read			*copy_way;
	t_room			*before;
	t_room			*current;

	copy_way = way->links;
	current = find_room_by_str(info, copy_way->next->str);
	before = find_room_by_str(info, copy_way->str);
	while (copy_way->next->next != NULL)
	{
		if (before->ant == 0 && current->ant != 0
			&& current->ant == ant)
		{
			if (info->color_ant == current->ant)
				move_ant(before, current, space, 1);
			else if (info->color_ways == 1)
				move_ant(before, current, space, way->id);
			else
				move_ant(before, current, space, 0);
			way->ants = 1;
		}
		copy_way = copy_way->next;
		if (copy_way->next && (before = current))
			current = find_room_by_str(info, copy_way->next->str);
	}
}

void				recursive_find_ant_on_ways(t_all_info *info,
	t_ways *copy_ways, int ant, int *space)
{
	t_room			*end;

	end = find_room_by_str(info, info->end);
	if (copy_ways)
	{
		find_ant_and_muve(info, copy_ways, ant, space);
		put_ant_on_end_pos(end, copy_ways);
		if (copy_ways->next)
			recursive_find_ant_on_ways(info, copy_ways->next, ant, space);
	}
}

void				algorithm(t_all_info *info)
{
	t_room			*end;
	int				space;
	size_t			ant;

	end = find_room_by_str(info, info->end);
	while (info->current_ant <= info->total_start_ants
		|| check_ants_on_ways(info))
	{
		space = 0;
		ant = 1;
		while (ant <= info->current_ant + 1)
		{
			recursive_find_ant_on_ways(info, info->ways, ant, &space);
			ant++;
		}
		info->total_value = 0;
		recursive_put_ants_second_room(info, info->ways, end, &space);
		ft_printf("\n");
	}
}
