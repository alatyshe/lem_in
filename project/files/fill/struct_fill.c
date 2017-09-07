/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void					fill_struct(t_all_info *info, char *read)
{
	static int			count;

	if (!count)
		count = 0;
	if (count == 0 && read[0] == '#')
		check_for_cmd(info, read);
	else if (read[0] == '#' && read[1] != '#')
		;
	else if (count == 0 && ++count)
		fill_count_ants(info, read);
	else if (ft_strchr(read, '-'))
		fill_links(info, &info->rooms, read);
	else if (read[0] == '#' || !ft_strchr(read, '-'))
		get_check_room(info, read);
	else
		info->error = 1;
	info->error += check_rooms_coord_repeat(info);
}
