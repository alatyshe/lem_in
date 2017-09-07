/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void				check_for_cmd(t_all_info *info, char *read)
{
	char		*str;

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
	if (!ft_strcmp(read, "##end")
		|| !ft_strcmp(read, "##start"))
		info->error = 1;
}
