/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_read				*get_last_link(t_read *links)
{
	t_read			*link;

	link = links;
	if (links)
	{
		while (link->next)
			link = link->next;
		return (link);
	}
	return (NULL);
}

int					repeat_char_str(char *str, char c)
{
	int				counter;

	counter = 0;
	while (*str)
	{
		if (*str++ == c)
			counter++;
	}
	return (counter);
}
