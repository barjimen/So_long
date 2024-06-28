/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:10:40 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/28 21:12:45 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



void load_sprites(t_so_long    *so_long)
{
	so_long->mlx_data.sprites[FLOOR] = load_xpm(so_long->mlx_data.mlx_ptr, "./img/circle.xpm");
	so_long->mlx_data.sprites[PLAYER] = load_xpm(so_long->mlx_data.mlx_ptr, "./img/circle2.xpm");
}

void create_background(t_so_long *so_long)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	while (y < so_long->map_h)
	{
		while (x < so_long->map_w)
		{
			if(so_long->map[y][x] != '1')
				put_img_to_img(so_long->mlx_data.img, so_long->mlx_data.sprites[FLOOR], (W_SIZE/2 - so_long->map_w/2) + x*32-(32*j), (H_SIZE/4 - so_long->map_h/2) + y*16+(16*i));
			else if(so_long->map[y ][x] != '0')
				put_img_to_img(so_long->mlx_data.img, so_long->mlx_data.sprites[FLOOR],(W_SIZE/2 - so_long->map_w/2) + x*32-(32*j), (H_SIZE/4 - so_long->map_h/2) + y*16+(16*i));
			if(so_long->map[y][x] == 'P')
				put_img_to_img(so_long->mlx_data.img,so_long->mlx_data.sprites[PLAYER], (W_SIZE/2 - so_long->map_w/2) + x*32-(32*j), (H_SIZE/4 - so_long->map_h/2) + y*16);
			x++;
			i++;
		}
		x = 0;
		i = 0;
		j++;
		y++;
	}
	
	mlx_put_image_to_window(so_long->mlx_data.mlx_ptr, so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
		
}
	
	

void    render_map(t_so_long    *so_long)
{
	t_data *data;
	
	data = &so_long->mlx_data;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_SIZE, H_SIZE, "Hello world!");
	data->img = create_image(data->mlx_ptr, W_SIZE, H_SIZE);
	 
	load_sprites(so_long);
	create_background(so_long);
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	printf("%s\n", so_long->map[0]);
}