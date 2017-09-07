/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int		isdigit_str(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}
