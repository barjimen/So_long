/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_char_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:31:39 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/08 22:44:39 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	fill_map(char **map, int width, int height)
{
	map[height][width] = 'P';
	if (map[height + 1][width] != '1' && map[height + 1][width] != 'P')
		fill_map(map, width, height + 1);
	if (map[height - 1][width] != '1' && map[height - 1][width] != 'P')
		fill_map(map, width, height - 1);
	if (map[height][width + 1] != '1' && map[height][width + 1] != 'P')
		fill_map(map, width + 1, height);
	if (map[height][width - 1] != '1' && map[height][width - 1] != 'P')
		fill_map(map, width - 1, height);
}

void	is_map_valid(void *data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'P')
		fill_map(so_long->map, x, y);
}

void	is_valid_e_c(void *data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'C')
		exit_msg(C_MSG);
	else if (so_long->map[y][x] == 'E')
		exit_msg(E_MSG);
}

void	is_char(void *data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'C')
		so_long->maps.c++;
	else if (so_long->map[y][x] == 'P')
	{
		so_long->maps.p++;
		so_long->player.player_moves = 0;
		so_long->player.x = x;
		so_long->player.y = y;
	}
	else if (so_long->map[y][x] == 'E')
	{
		so_long->maps.e++;
		so_long->e_pos.x = x;
		so_long->e_pos.y = y;
	}
}

void	map_iter_context(char **map, void (*f)(void *, int x, int y),
	void *data)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			f(data, x, y);
			x++;
		}
		y++;
	}
}
