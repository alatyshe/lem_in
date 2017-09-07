/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

t_read				*reading(t_all_info *info)
{
	t_read			*new;
	t_read			*result;
	char			*str;

	result = NULL;
	str = NULL;
	while (get_next_line(0, &str) > 0)
	{
		if (result == NULL && (result = create_t_read()))
			new = result;
		else
		{
			new->next = create_t_read();
			new = new->next;
		}
		new->str = ft_strdup(str);
		fill_struct(info, str);
		free(str);
		str = NULL;
		if (info->error == 1)
			break ;
	}
	if (str != NULL)
		free(str);
	return (result);
}
