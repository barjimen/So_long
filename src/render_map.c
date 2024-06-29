/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:10:40 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/30 00:28:09 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void load_sprites(t_so_long *so_long)
{
	so_long->mlx_data.sprites[FLOOR] = load_xpm(so_long->mlx_data.mlx_ptr, "./img/suelo1.xpm");
	so_long->mlx_data.sprites[PLAYER] = load_xpm(so_long->mlx_data.mlx_ptr, "./img/circle2.xpm");
	so_long->mlx_data.sprites[WALL] = load_xpm(so_long->mlx_data.mlx_ptr, "./img/sea.xpm");
	so_long->mlx_data.sprites[EXIT] = load_xpm(so_long->mlx_data.mlx_ptr, "./img/exit.xpm");
	so_long->mlx_data.sprites[COLLECT] = load_xpm(so_long->mlx_data.mlx_ptr, "./img/collect.xpm");
}

/*void create_background(t_so_long *so_long)
{
	int x = 0;
	int y = 0;
	while (y < so_long->map_h)
	{
		while (x < so_long->map_w)
		{
			if (so_long->map[y][x] != '1')
				put_img_to_img(so_long->mlx_data.img,
					so_long->mlx_data.sprites[FLOOR],
					(W_SIZE / 2 - so_long->map_w / 2) + x * 32 - (32 * y),
					(H_SIZE / 4 - so_long->map_h / 2) + y * 16 + (16 * x));
			else if (so_long->map[y][x] != '0')
				put_img_to_img(so_long->mlx_data.img, so_long->mlx_data.sprites[FLOOR], (W_SIZE/2 - so_long->map_w/2) + x * 32-(32*y), (H_SIZE/4 - so_long->map_h/2) + y * 16+(16*x));
			if (so_long->map[y][x] == 'P')
				put_img_to_img(so_long->mlx_data.img, so_long->mlx_data.sprites[PLAYER], (W_SIZE/2 - so_long->map_w/2) + x * 32-(32*y), (H_SIZE/4 - so_long->map_h/2) + y * 16);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(so_long->mlx_data.mlx_ptr, so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
}*/
/*void background_iter(t_so_long *so_long, void (*f)(t_so_long *so_long, int x, int y))
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	while (y < so_long->map_h)
	{
		while (x < so_long->map_w)
		{
			f(so_long, x , y);
			x++;
			i++;
		}
		x = 0;
		i = 0;
		j++;
		y++;
	}
	
}*/

void	create_background(void	*data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == '1')
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[WALL],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 32 - (32 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + 10 + y * 16 + (16 * x));
	if (ft_strchr("0PCE", so_long->map[y][x]))
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[FLOOR],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 32 - (32 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + y * 16 + (16 * x));
}
void	create_items(void	*data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'P')
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[PLAYER],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 32 - (32 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + y * 16 - (6 * x));
	else if (so_long->map[y][x] == 'C')
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[COLLECT],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 32 - (32 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + y * 16 + (10 * x));
	else if (so_long->map[y][x] == 'E')
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[EXIT],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 32 - (32 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + y * 16 + (16 * x));
}

void render_map(t_so_long *so_long)
{
	t_data *data;

	data = &so_long->mlx_data;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_SIZE, H_SIZE, "Hello world!");
	data->img = create_image(data->mlx_ptr, W_SIZE, H_SIZE);

	load_sprites(so_long);
	map_iter_context(so_long->map, create_background, so_long);
	map_iter_context(so_long->map, create_items, so_long);

	//create_background(so_long);
	//background_iter(so_long, so_long);
	//create_background(so_long);
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	printf("%s\n", so_long->map[0]);
}