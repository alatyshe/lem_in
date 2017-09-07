/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_start_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

static void			fill_start(t_all_info *info)
{
	if (info->start == NULL
		&& info->wait_start == 0
		&& info->wait_end == 0)
		info->wait_start = 1;
	else
		info->error = 1;
}

static void			fill_end(t_all_info *info)
{
	if (info->end == NULL
		&& info->wait_end == 0
		&& info->wait_start == 0)
		info->wait_end = 1;
	else
		info->error = 1;
}

static void			check_watch_ant_cmd(t_all_info *info, char *read)
{
	char			*str;

	str = NULL;
	if (ft_strchr(read, ' '))
	{
		str = ft_strchr(read, ' ');
		if (isdigit_str(str + 1) && str[0] != '0')
			*str++ = '\0';
		if (str && !ft_strcmp(read, "##watch_ant"))
		{
			if (info->color_ant == 0)
				info->color_ant = ft_atoi(str);
		}
	}
}

void				fill_start_end(t_all_info *info, char *read)
{
	check_watch_ant_cmd(info, read);
	if (!strcmp(read, "##start"))
		fill_start(info);
	else if (!strcmp(read, "##end"))
		fill_end(info);
}
