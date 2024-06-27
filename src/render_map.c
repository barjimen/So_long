/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:10:40 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/27 23:42:36 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



void load_sprites(t_so_long    *so_long)
{
	so_long->mlx_data.sprites[FLOOR] = load_xpm(so_long->mlx_data.mlx_ptr, "./img/sea.xpm");
	so_long->mlx_data.sprites[PLAYER] = load_xpm(so_long->mlx_data.mlx_ptr, "./img/circle2.xpm");
}

void create_background(t_so_long *so_long)
{
	put_img_to_img(so_long->mlx_data.img, so_long->mlx_data.sprites[FLOOR], 20, 20);
}

void    render_map(t_so_long    *so_long)
{
	t_data *data;
	
	data = &so_long->mlx_data;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_SIZE, H_SIZE, "Hello world!");
	data->img = create_image(data->mlx_ptr, W_SIZE, H_SIZE);
	 
	load_sprites(so_long);

	put_img_to_img(data->img, data->sprites[PLAYER], 20, 20);
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	printf("%s\n", so_long->map[0]);
}