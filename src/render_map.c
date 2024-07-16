/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:10:40 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/16 21:50:12 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_sprites(t_so_long *so_long)
{
	so_long->mlx_data.sprites[FLOOR] = load_xpm(so_long->mlx_data.mlx_ptr,
			FLOOR_SRC);
	so_long->mlx_data.sprites[PLAYER_UP] = load_xpm(so_long->mlx_data.mlx_ptr,
			ROOMBA_SRC_UP);
	so_long->mlx_data.sprites[PLAYER_DOWN] = load_xpm(so_long->mlx_data.mlx_ptr,
			ROOMBA_SRC_DWN);
	so_long->mlx_data.sprites[PLAYER_LEFT] = load_xpm(so_long->mlx_data.mlx_ptr,
			ROOMBA_SRC_LFT);
	so_long->mlx_data.sprites[PLAYER_RGHT] = load_xpm(so_long->mlx_data.mlx_ptr,
			ROOMBA_SRC_RHT);
	so_long->mlx_data.sprites[WALL] = load_xpm(so_long->mlx_data.mlx_ptr,
			WALLS_SRC);
	so_long->mlx_data.sprites[EXIT] = load_xpm(so_long->mlx_data.mlx_ptr,
			EXIT_KO_SRC);
	so_long->mlx_data.sprites[EXIT_OK] = load_xpm(so_long->mlx_data.mlx_ptr,
			EXIT_OK_SRC);
	so_long->mlx_data.sprites[COLLECT] = load_xpm(so_long->mlx_data.mlx_ptr,
			COLLECT_SRC);
}

void	create_background(void	*data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == '1')
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[WALL],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 64 - (64 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + 20 + y * 32 + (32 * x));
	if (ft_strchr("0PCE", so_long->map[y][x]))
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[FLOOR],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 64 - (64 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + y * 32 + (32 * x));
}

void	create_items(void	*data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'C')
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[COLLECT],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 64 - (64 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + y * 32 + (32 * x));
	else if (so_long->map[y][x] == 'E' &&
		so_long->player.collect_num != so_long->maps.c)
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[EXIT],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 64 - (64 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + y * 32 + (32 * x));
	else if (so_long->player.collect_num == so_long->maps.c
		&& so_long->map[y][x] == 'E')
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[EXIT_OK],
			(W_SIZE / 2 - so_long->map_w / 2) + x * 64 - (64 * y),
			(H_SIZE / 4 - so_long->map_h / 2) + y * 32 + (32 * x));
}

void	create_player(void	*data, int sprite_type)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	put_img_to_img(so_long->mlx_data.img,
		so_long->mlx_data.sprites[sprite_type],
		(W_SIZE / 2 - so_long->map_w / 2)
		+ so_long->player.x * 64 - (64 * so_long->player.y),
		(H_SIZE / 4 - so_long->map_h / 2) + so_long->player.y
		* 32 + (32 * so_long->player.x));
}

void	render_map(t_so_long *so_long)
{
	t_data	*data;

	data = &so_long->mlx_data;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			W_SIZE, H_SIZE, "So_Long by Barjimen");
	data->img = create_image(data->mlx_ptr, W_SIZE, H_SIZE);
	load_sprites(so_long);
	map_iter_context(so_long->map, create_background, so_long);
	map_iter_context(so_long->map, create_items, so_long);
	create_player(so_long, PLAYER_DOWN);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, 250, 0xFFFFFF, MSG_GUIDE);
}
