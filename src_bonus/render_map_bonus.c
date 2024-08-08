/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:10:40 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/08 23:34:25 by barjimen         ###   ########.fr       */
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
	so_long->mlx_data.sprites[EXIT_1] = load_xpm(so_long->mlx_data.mlx_ptr,
			EXIT_KO_SRC);
	so_long->mlx_data.sprites[EXIT_OK_1] = load_xpm(so_long->mlx_data.mlx_ptr,
			EXIT_OK_SRC);
	so_long->mlx_data.sprites[COLLECT] = load_xpm(so_long->mlx_data.mlx_ptr,
			COLLECT_SRC);
	so_long->mlx_data.sprites[COVER] = load_xpm(so_long->mlx_data.mlx_ptr,
			COVER_SRC);
	so_long->mlx_data.sprites[ENEMY] = load_xpm(so_long->mlx_data.mlx_ptr,
			ENEMY_SRC);
	images_load(so_long, &so_long->exit_close, "./img/exit/red/00.xpm", 7);
	images_load(so_long, &so_long->exit_open, "./img/exit/00.xpm", 7);
}

void	create_background(void *data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == '1')
		put_img_to_img(so_long->mlx_data.img, so_long->mlx_data.sprites[WALL],
			so_long->w_offset + x * 64 - (64 * y), so_long->h_offset + 20 + y
			* 32 + (32 * x));
	if (ft_strchr("0PCEX", so_long->map[y][x]))
		put_img_to_img(so_long->mlx_data.img, so_long->mlx_data.sprites[FLOOR],
			so_long->w_offset + x * 64 - (64 * y), so_long->h_offset + y * 32
			+ (32 * x));
}

void	create_items(void *data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'C')
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[COLLECT], so_long->w_offset + x * 64 - (64
				* y), so_long->h_offset + y * 32 + (32 * x));
}

void	create_player(void *data, int sprite_type)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	put_img_to_img(so_long->mlx_data.img,
		so_long->mlx_data.sprites[sprite_type], so_long->w_offset
		+ so_long->player.x * 64 - (64 * so_long->player.y), so_long->h_offset
		+ so_long->player.y * 32 + (32 * so_long->player.x));
}

void	render_map(t_so_long *so_long)
{
	t_data	*data;

	data = &so_long->mlx_data;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, so_long->window_w,
			so_long->window_h, "So_Long by Barjimen");
	data->img = create_image(data->mlx_ptr, so_long->window_w,
			so_long->window_h);
	load_sprites(so_long);
	map_iter_context(so_long->map, create_background, so_long);
	map_iter_context(so_long->map, create_items, so_long);
	map_iter_context(so_long->map, create_enemy, so_long);
	create_player(so_long, PLAYER_DOWN);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	mlx_set_font(so_long->mlx_data.mlx_ptr, so_long->mlx_data.win_ptr,
		"12x24romankana");
}
