/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

static void			fill_coords(t_room *room,
	char *first, char *second)
{
	room->x = ft_atoi(first);
	room->y = ft_atoi(second);
}

static t_room		*fill_room(t_all_info *info, char *read)
{
	char			*first;
	char			*second;
	t_room			*room;

	if (total_chars_str(read, ' ') == 2
		&& (first = ft_strchr(read, ' ')) && read[0] != 'L')
	{
		*first++ = '\0';
		room = create_t_room();
		room->name = ft_strdup(read);
		second = first;
		if ((first = ft_strchr(second, ' ')))
		{
			*first++ = '\0';
			if (isdigit_str(first) && isdigit_str(second))
			{
				fill_coords(room, first, second);
				return (room);
			}
		}
		free(room->name);
		free(room);
	}
	info->error = 1;
	return (NULL);
}

static t_room		*fill_rooms(t_all_info *info, char *read)
{
	t_room			*room;

	if (read[0] == '#')
	{
		fill_start_end(info, read);
		return (NULL);
	}
	room = fill_room(info, read);
	if (room != NULL)
		return (room);
	info->error = 1;
	return (NULL);
}

void				get_check_room(t_all_info *info, char *read)
{
	t_room			*room;

	room = fill_rooms(info, read);
	if (room)
	{
		if (info->wait_start == 1)
		{
			info->start = room->name;
			info->wait_start = 0;
		}
		else if (info->wait_end == 1)
		{
			info->end = room->name;
			info->wait_end = 0;
		}
		if (info->rooms != NULL)
		{
			room->next = info->rooms;
			info->rooms = room;
		}
		else
			info->rooms = room;
	}
}
