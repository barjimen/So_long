/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:26:47 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/09 21:21:50 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_text(t_so_long *so_long)
{
	char	*moves;
	char	*collecti;
	char	*a;
	char	*b;

	a = ft_itoa(so_long->player.player_moves);
	b = ft_itoa(so_long->player.collect_num);
	moves = ft_strjoin("Moves: ", a);
	collecti = ft_strjoin("C: ", b);
	mlx_string_put(so_long->mlx_data.mlx_ptr,
		so_long->mlx_data.win_ptr, 32, 32, 0xFFFFFF, moves);
	mlx_string_put(so_long->mlx_data.mlx_ptr,
		so_long->mlx_data.win_ptr, so_long->window_w - 80,
		32, 0xFFFFFF, collecti);
	free(moves);
	free(collecti);
	free(a);
	free(b);
}

void	render_move(t_so_long *so_long, int sprite_type)
{
	so_long->player.player_moves += 1;
	item_removed(so_long);
	map_iter_context(so_long->map, create_items, so_long);
	create_player(so_long, sprite_type);
	mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,
		so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
	put_text(so_long);
}

void	move_player(t_so_long *so_long, int new_x, int new_y, int sprite_type)
{
	static int	moves;

	if (so_long->map[new_y][new_x] != '1')
	{
		create_cover(so_long, COVER);
		so_long->player.x = new_x;
		so_long->player.y = new_y;
		render_move(so_long, sprite_type);
		moves++;
		ft_printf("Moves: %d \n", moves);
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
