/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/lem_in.h"

int					main(int argc, char **argv)
{
	t_all_info		*info;
	t_read			*read;

	info = create_t_all_info();
	read = reading(info);
	if (argc >= 2 && ft_strcmp(argv[1], "-c") == 0)
		info->color_ways = 1;
	if (pass_check(info))
	{
		ways(info);
		if (info->error == 0)
		{
			print_read(read);
			ft_printf("\n");
			algorithm(info);
			return (0);
		}
	}
	ft_printf("ERROR\n");
	return (0);
}
