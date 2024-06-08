/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:31:39 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/08 20:45:38 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	exit_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_SUCCESS);
}

void	is_valid_p_c(char **map, int width, int height)
{
	int h;
    int w;
	
	w = 0;
	h = 0;
	while (h < height)
	{
		while (w < width)
		{	
			if (map[h][w] == 'C')
				exit_msg(C_MSG);//printf("no vale, hay una c :( \n");
			else if (map[h][w] == 'E')
				exit_msg(E_MSG);//printf("no vale, hay una e :( \n");
			w++;
		}
		w = 0;
		h++;
	}
}

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
int is_map_valid(char **map,int width, int height)
{
	static int h;
    static int w;
	
	while (h < height)
	{
		while (w < width)
		{	
			if (map[h][w] == 'P')
			{
				llenar_de_agua(map, w, h);
			}
			w++;
		}
		w = 0;
		h++;
	}
	is_valid_p_c(map, width, height);
	return(0);
}

void is_char(char **map,int width, int height)
{
	static int c;
	static int e;
	static int p;
    static int h;
    static int w;
	
	while (h < height)
	{
		while (w < width)
		{	
			if (map[h][w] == 'C')
				c++;
			else if (map[h][w] == 'P')
				p++;
			else if (map[h][w] == 'E')
				e++;
			w++;
		}
		w = 0;
		h++;
	}
	if (c < 1 || p != 1 || e != 1)
		exit_msg(CPE_MSG);
}
