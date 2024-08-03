/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:13:57 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/03 16:21:28 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_walled(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			if (map[i][j] != '1' && (i == 0 || j == 0
				|| i == height - 1 || j == width - 1))
				printf("no es 1\n");
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'X')
				exit_msg(MAP_CHAR_KO_B);
			j++;
		}
		j = 0;
		i++;
	}
}

int	height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (i < 3)
		exit_msg(MAP_H_KO);
	return (i);
}

int	length_map(char **map)
{
	int	i;
	int	length1;
	int	length2;

	i = -1;
	length1 = ft_strlen(map[0]) - 1;
	if (length1 < 3)
		exit_msg(MAP_W_KO);
	while (map[++i])
	{
		length2 = ft_strlen(map[i]);
		if (map[i][length2 - 1] == '\n')
			length2--;
		if (length1 != length2)
			exit_msg(MAP_LENGHT_KO);
	}
	return (length1);
}

char	*map_check(t_so_long *so_long)
{
	int	width;
	int	height;

	width = length_map(so_long->map);
	height = height_map(so_long->map);
	if ((width == 3 && height < 5) || (height == 3 && width < 5))
		exit_msg(MAP_KO);
	is_walled(so_long->map, width, height);
	map_iter_context(so_long->map, is_char, so_long);
	if (so_long->maps.c < 1 || so_long->maps.p != 1 || so_long->maps.e != 1)
		exit_msg(CPE_MSG);
	map_iter_context(so_long->map, is_map_valid, so_long);
	map_iter_context(so_long->map, is_valid_e_c, so_long);
	so_long->map_h = height;
	so_long->map_w = width;
	return (0);
}

void	item_removed(t_so_long	*so_long)
{
	if (so_long->map[so_long->player.y][so_long->player.x] == 'C')
	{
		so_long->player.collect_num++;
		printf("Tienes un total de coleccionables: %d\n",
			so_long->player.collect_num);
		so_long->map[so_long->player.y][so_long->player.x] = '0';
	}
	if (so_long->player.collect_num == so_long->maps.c
		&& so_long->map[so_long->player.y][so_long->player.x] == 'E')
	{
		mlx_destroy_window(so_long->mlx_data.mlx_ptr,
			so_long->mlx_data.win_ptr);
		exit_msg(WIN);
	}
	if (so_long->map[so_long->player.y][so_long->player.x] == 'X')
	{
		mlx_destroy_window(so_long->mlx_data.mlx_ptr,
			so_long->mlx_data.win_ptr);
		exit_msg(DEAD);
	}
}
