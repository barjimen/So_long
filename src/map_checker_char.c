/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:31:39 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/04 23:58:31 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		exit (1);
}
