/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

void				fill_count_ants(t_all_info *info, char *read)
{
	intmax_t		ants;

	if (isdigit_str(read))
	{
		ants = ft_atoi(read);
		info->total_start_ants = ants;
		if (ants < 1 || ants > 4294967295)
			info->error = 1;
	}
	else
		info->error = 1;
}
