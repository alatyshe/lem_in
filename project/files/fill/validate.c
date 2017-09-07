/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

int					check_rooms_coord_repeat(t_all_info *info)
{
	t_room			*copy_room;
	t_room			*check;
	int				counter;
	int				counter2;

	check = info->rooms;
	if (info->rooms)
		while (check)
		{
			counter = 0;
			counter2 = 0;
			copy_room = info->rooms;
			while (copy_room)
			{
				if (ft_strcmp(copy_room->name, check->name) == 0)
					++counter;
				if (copy_room->y == check->y && copy_room->x == check->x)
					++counter2;
				copy_room = copy_room->next;
			}
			if (counter > 1 || counter2 > 1)
				return (1);
			check = check->next;
		}
	return (0);
}

int					pass_check(t_all_info *info)
{
	int				counter;

	counter = 0;
	counter += check_rooms_coord_repeat(info);
	counter += info->error;
	counter += (info->start == NULL) ? 1 : 0;
	counter += (info->end == NULL) ? 1 : 0;
	if (counter > 0)
		return (0);
	return (1);
}
