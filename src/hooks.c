/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:26:47 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/08 23:18:48 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	create_cover(void	*data, int sprite_type)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	put_img_to_img(so_long->mlx_data.img,
		so_long->mlx_data.sprites[sprite_type], so_long->w_offset
		+ so_long->player.x * 64 - (64 * so_long->player.y),
		so_long->h_offset + so_long->player.y
		* 32 + (32 * so_long->player.x));
}

void	render_move(t_so_long *so_long, int sprite_type)
{
	char	*moves;
	char	*collecti;
	char	*a;
	char	*b;

	a = ft_itoa(so_long->player.player_moves);
	b = ft_itoa(so_long->player.collect_num);
	so_long->player.player_moves += 1;
	moves = ft_strjoin("Numero de movimientos: ", a);
	collecti = ft_strjoin("Numero de coleccionables: ", b);
	ft_printf("Se ha movido %s veces\n", moves);
	item_removed(so_long);
	map_iter_context(so_long->map, create_items, so_long);
	create_player(so_long, sprite_type);
	mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,
		so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
	mlx_string_put(so_long->mlx_data.mlx_ptr,
		so_long->mlx_data.win_ptr, 64, 64, 0xFFFFFF, moves);
	mlx_string_put(so_long->mlx_data.mlx_ptr,
		so_long->mlx_data.win_ptr, 64, 128, 0xFFFFFF, collecti);
	free(moves);
	free(collecti);
	free(a);
	free(b);
}

void	move_player(t_so_long *so_long, int new_x, int new_y, int sprite_type)
{
	if (so_long->map[new_y][new_x] != '1')
	{
		create_cover(so_long, COVER);
		so_long->player.x = new_x;
		so_long->player.y = new_y;
		render_move(so_long, sprite_type);
	}
}

int	close_w(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit_msg(C_WINDOW);
	return (0);
}

int	key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(so_long->mlx_data.mlx_ptr,
			so_long->mlx_data.win_ptr);
		exit(0);
	}
	if (keycode == XK_Up || keycode == XK_w)
		move_player(so_long, so_long->player.x,
			so_long->player.y - 1, PLAYER_UP);
	else if (keycode == XK_Down || keycode == XK_s)
		move_player(so_long, so_long->player.x,
			so_long->player.y + 1, PLAYER_DOWN);
	else if (keycode == XK_Right || keycode == XK_d)
		move_player(so_long, so_long->player.x + 1,
			so_long->player.y, PLAYER_RGHT);
	else if (keycode == XK_Left || keycode == XK_a)
		move_player(so_long, so_long->player.x - 1,
			so_long->player.y, PLAYER_LEFT);
	return (0);
}
