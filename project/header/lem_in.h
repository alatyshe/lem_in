/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define BLACK		"\x1b[37m"
# define RESET		"\x1b[0m"

# define SAME		0

# define CHAR_BIT	8
# define CHAR_MIN	–128
# define CHAR_MAX	127
# define UCHAR_MAX	255
# define SHRT_MIN	–32768
# define SHRT_MAX	32767
# define USHRT_MAX	65535
# define INT_MIN	–2147483648
# define INT_MAX	2147483647
# define UINT_MAX	4294967295
# define _I64_MIN	-9223372036854775808
# define _I64_MAX	9223372036854775807
# define _UI64_MAX	18446744073709551615

# include "../libft/header/libft.h"
# include "../ft_printf/header/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>

/*
**	reading and ways
*/
typedef struct		s_read
{
	char			*str;
	struct s_read	*next;
}					t_read;

/*
**	for all ways and they values. values - way from a to b
*/
typedef struct		s_ways
{
	int				id;
	int				total_links;
	int				ants;
	t_read			*links;
	struct s_ways	*next;
}					t_ways;

/*
**	all info about room include links beetween rooms like:
**		coord, ant, links to other rooms, and next room in list
**		value - for finding shortest way
**		total_links_room - for count total links
*/
typedef struct		s_room
{
	char			*name;
	int				value;
	int				links_in_room;
	int				y;
	int				x;
	size_t			ant;
	struct s_links	*links;
	struct s_room	*next;

}					t_room;

/*
**	links for use in room struct
*/
typedef struct		s_links
{
	char			*room_name;
	t_room			*link;
	struct s_links	*next;
}					t_links;

/*
**	all info in prog
*/
typedef struct		s_all_info
{
	char			wait_start;
	char			*start;
	char			wait_end;
	char			*end;
	int				error;
	size_t			color_ant;
	size_t			total_start_ants;
	size_t			current_ant;
	int				color_ways;
	int				total_ways;
	int				total_value;
	t_ways			*ways;
	t_room			*rooms;
}					t_all_info;

void				save_all_ways(t_all_info *info, t_room *start, t_room *end);
int					pass_check(t_all_info *info);
void				check_for_cmd(t_all_info *info, char *read);
int					find_room_biggest_value(t_links *link);
t_room				*find_room_by_value(t_links *link, int value);
t_room				*find_room_by_str(t_all_info *info, char *to_find);
int					last_room_value_empty(t_all_info *info, t_room *end_room);
t_read				*get_last_link(t_read *room);
t_room				*find_room(t_room *rooms, char *to_find);
void				get_check_room(t_all_info *info, char *read);
void				put_ant_on_start_pos(t_all_info *info);
void				put_ant_on_end_pos(t_room *room, t_ways *way);
int					check_ants_on_ways(t_all_info *info);
void				put_ant_second_room(t_all_info *info,
	t_ways *way, int *space);
void				recursive_put_ants_second_room(t_all_info *info,
	t_ways *copy_ways, t_room *end, int *space);
void				find_ant_and_muve(t_all_info *info, t_ways *way,
	size_t ant, int *space);
void				recursive_find_ant_on_ways(t_all_info *info,
	t_ways *copy_ways, int ant, int *space);
void				algorithm(t_all_info *info);
t_read				*copy_read(t_read *read);
t_read				*reading(t_all_info	*info);
void				free_links(t_read *link);
void				free_room(t_room *room);
void				ways(t_all_info *info);
int					repeat_char_str(char *str, char c);
void				move_ant(t_room *before, t_room *current,
	int *space, int color);
void				print_read(t_read *read);
int					total_chars_str(char *str, char to_find);
int					check_rooms_coord_repeat(t_all_info *info);
t_read				*create_t_read(void);
t_all_info			*create_t_all_info(void);
t_room				*create_t_room(void);
t_ways				*create_t_ways(void);
t_links				*create_t_links(t_links *in, t_room *room);
void				fill_struct(t_all_info *info, char *read);
void				fill_count_ants(t_all_info *info, char *read);
void				fill_links(t_all_info *info, t_room **rooms, char *read);
void				fill_start_end(t_all_info *info, char *read);
int					fill_room_value(t_room *room, int value);
#endif
