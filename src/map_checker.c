/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:13:57 by barjimen          #+#    #+#             */
/*   Updated: 2024/05/30 21:37:47 by barjimen         ###   ########.fr       */
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
		exit(1);
	return (i);
}	

int length_map(char **map)
{
	int i;
	int length1;
	int length2;
	

	i = 0;
	length1 = ft_strlen(map[i]) - 1;
	if (length1 < 3)
		exit(1);	// error de mapa vacio
	while (map[++i])
	{
		length2 = ft_strlen(map[i]);
		if (map[i][length2 - 1] == '\n')
			length2--;
		if (length1 != length2)
			exit(1);
	}
	return (length1);
}

char *map_check(char **map)
{
	int width;
	int height;
	
	width = length_map(map);
	height = height_map(map);
	if ((width == 3 && height < 5) || (height == 3 && width < 5)) //ya que no seria un mapa valido (no caben P, C y E)
		exit(1);
	is_walled(map, width, height);
	printf("ancho mide %d; altura mide %d\n", width, height);
	return (0);
}