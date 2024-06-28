/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:13:57 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/28 20:15:21 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void is_walled(char **map, int width, int height)
{
	int i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			if (map[i][j] != '1' && (i == 0 || j == 0 || i == height - 1 || j == width - 1))
				printf("no es 1\n");
			if (map[i][j] != '1'&& map[i][j] != '0' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				exit_msg(MAP_CHAR_KO);//para salir si en algun caso es diferente de cualquiera de los char que necesito :)
			j++;
		}
		j = 0;
		i++;
	}
	
}

int	height_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	if (i < 3)
		exit_msg(MAP_H_KO);
	return (i);
}	

int length_map(char **map)
{
	int i;
	int length1;
	int length2;
	
	i = -1;
	length1 = ft_strlen(map[0]) - 1;
	if (length1 < 3)
		exit_msg(MAP_W_KO);	// error de mapa vacio
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

char *map_check(t_so_long *so_long)
{
	int width;
	int height;
	
	width = length_map(so_long->map);
	height = height_map(so_long->map);
	if ((width == 3 && height < 5) || (height == 3 && width < 5)) //ya que no seria un mapa valido (no caben P, C y E)
		exit_msg(MAP_KO);
	is_walled(so_long->map, width, height);
	//printf("ancho mide %d; altura mide %d\n", width, height);
	
	map_iter_context(so_long->map, is_char, so_long);
	if (so_long->maps.c < 1 || so_long->maps.p != 1 || so_long->maps.e != 1)
		exit_msg(CPE_MSG);
	map_iter_context(so_long->map, is_map_valid, so_long);
	map_iter_context(so_long->map, is_valid_p_c, so_long);
	so_long->map_h = height;
	so_long->map_w = width;
	return (0);
}