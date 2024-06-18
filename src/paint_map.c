/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:56:41 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/18 22:11:34 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void paint_map(int width, int height, char *img, t_so_long *so_long)
{
    void *floor;
    char *f_path;
    int h;
	int w;
    void *p;

    h = 0;
    w = 0;
    f_path = "./img/sea.xpm";
    floor = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, f_path, &h, &w);
    p = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, "./img/circle2.xpm", &h, &w);
    while (height)
	{
		while (width)
		{
            if(so_long->map[height - 1][width - 1] != '1')
                mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, floor, width * 50, height * 50);
            else
			    mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, img, width * 50, height * 50);
			if(so_long->map[height - 1][width - 1] != '0' && so_long->map[height - 1][width - 1] != '1')
                mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, p, width * 50, height * 50);
            width--;
		}
		width = length_map(so_long->map);
		height--;
	}
    mlx_destroy_image(so_long->mlx_data.mlx_ptr, floor);
    mlx_destroy_image(so_long->mlx_data.mlx_ptr, p);
}