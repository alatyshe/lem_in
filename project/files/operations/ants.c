/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

int					check_ants_on_ways(t_all_info *info)
{
	t_ways			*copy_ways;

	if (info->ways)
	{
		copy_ways = info->ways;
		while (copy_ways)
		{
			if (copy_ways->ants)
				return (1);
			copy_ways = copy_ways->next;
		}
	}
	return (0);
}

void				put_ant_on_start_pos(t_all_info *info)
{
	t_room			*current;

	current = find_room_by_str(info, info->start);
	if (current->ant == 0)
	{
		if (info->current_ant <= info->total_start_ants)
			current->ant = info->current_ant++;
	}
}

void				put_ant_on_end_pos(t_room *room, t_ways *way)
{
	if (room->ant != 0)
	{
		way->ants = 0;
		room->ant = 0;
	}
}
