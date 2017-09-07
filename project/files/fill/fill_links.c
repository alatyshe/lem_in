/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_room				*find_room(t_room *rooms, char *to_find)
{
	t_room		*room;

	room = rooms;
	while (room)
	{
		if (!ft_strcmp(room->name, to_find))
			return (room);
		room = room->next;
	}
	return (NULL);
}

int					check_rooms(t_room *first, t_room *second)
{
	t_links		*link;

	if (first)
	{
		link = first->links;
		while (link)
		{
			if (!ft_strcmp(link->room_name, second->name))
				return (0);
			link = link->next;
		}
	}
	if (!ft_strcmp(first->name, second->name))
		return (0);
	return (1);
}

void				fill_links(t_all_info *info, t_room **rooms, char *read)
{
	char		*link_1;
	char		*link_2;
	t_room		*room_1;
	t_room		*room_2;

	link_1 = read;
	link_2 = ft_strchr(read, '-');
	*link_2++ = '\0';
	room_1 = find_room((*rooms), link_1);
	room_2 = find_room((*rooms), link_2);
	if ((!room_1 || !room_2 || info->start == NULL || info->end == NULL)
		&& (info->error = 1))
		return ;
	if (!check_rooms(room_1, room_2) || !ft_strcmp(room_1->name, room_2->name))
		return ;
	if (!room_1->links)
		room_1->links = create_t_links(room_1->links, room_2);
	else
		create_t_links(room_1->links, room_2);
	if (!room_2->links)
		room_2->links = create_t_links(room_2->links, room_1);
	else
		create_t_links(room_2->links, room_1);
	room_1->links_in_room++;
	room_2->links_in_room++;
}
