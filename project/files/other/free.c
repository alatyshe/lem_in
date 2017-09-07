/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void				free_links(t_read *link)
{
	t_read			*copy_link;
	t_read			*copy_next_link;

	if (link)
	{
		copy_link = link;
		while (copy_link)
		{
			copy_next_link = copy_link->next;
			if (copy_link->str)
				free(copy_link->str);
			free(copy_link);
			copy_link = copy_next_link;
		}
	}
}

void				free_room(t_room *room)
{
	if (room != NULL)
	{
		if (room->name != NULL)
			free(room->name);
		free(room);
	}
}
