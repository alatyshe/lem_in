/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

int					find_room_biggest_value(t_links *link)
{
	t_links			*copy;
	int				res;

	res = -2147483648;
	if (link)
	{
		copy = link;
		while (copy)
		{
			if (res < copy->link->value)
				res = copy->link->value;
			copy = copy->next;
		}
	}
	return (res);
}

t_room				*find_room_by_value(t_links *link, int value)
{
	t_links			*copy;

	if (link)
	{
		copy = link;
		while (copy)
		{
			if (copy->link->value == value)
				return (copy->link);
			copy = copy->next;
		}
	}
	return (NULL);
}

t_room				*find_room_by_str(t_all_info *info, char *to_find)
{
	t_room			*room;

	room = info->rooms;
	if (room)
	{
		while (room)
		{
			if (!ft_strcmp(room->name, to_find))
				return (room);
			room = room->next;
		}
	}
	return (NULL);
}

int					fill_room_value(t_room *room, int value)
{
	t_links			*link;
	int				counter;

	counter = 0;
	link = room->links;
	if (link)
	{
		while (link)
		{
			if (link->link->value == 0)
			{
				counter = 1;
				link->link->value = value;
			}
			link = link->next;
		}
	}
	return (counter);
}

int					last_room_value_empty(t_all_info *info, t_room *end_room)
{
	t_links			*links;

	links = end_room->links;
	if (links)
	{
		while (links)
		{
			if (links->link->value == 0)
				return (1);
			links = links->next;
		}
	}
	else
		info->error = 1;
	return (0);
}
