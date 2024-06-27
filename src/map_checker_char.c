/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:31:39 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/28 01:23:27 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void llenar_de_agua(char **map, int width, int height)
{
	map[height][width] = 'P';
	if (map[height + 1][width] != '1' && map[height + 1][width] != 'P')
		llenar_de_agua(map, width, height + 1);
	if (map[height - 1][width] != '1' && map[height - 1][width] != 'P')
		llenar_de_agua(map, width, height - 1);
	if (map[height][width + 1] != '1' && map[height][width + 1] != 'P')
		llenar_de_agua(map, width + 1, height);
	if (map[height][width - 1] != '1' && map[height][width - 1] != 'P')
		llenar_de_agua(map, width - 1, height);
}
void is_map_valid(void *data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'P')
	{
		llenar_de_agua(so_long->map, x, y);
	}
}

void is_valid_p_c(void *data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'C')
		exit_msg(C_MSG);//printf("no vale, hay una c :( \n");
	else if (so_long->map[y][x] == 'E')
		exit_msg(E_MSG);//printf("no vale, hay una e :( \n");
}

void is_char(void *data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'C')
		so_long->maps.c++;
	else if (so_long->map[y][x] == 'P')
		so_long->maps.p++;
	else if (so_long->map[y][x] == 'E')
		so_long->maps.e++;
}

void map_iter_context(char **map, void (*f)(void *, int x, int y), void *data)
{
	int x;
    int y;
	
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