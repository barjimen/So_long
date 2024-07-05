/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:26:47 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/05 21:12:06 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void render_move(t_so_long *so_long)
{
	char *moves;

	so_long->player.player_moves++;
	printf("Se ha movido %d veces\n", so_long->player.player_moves);
	item_removed(so_long);
	map_iter_context(so_long->map, create_background, so_long);
	map_iter_context(so_long->map, create_items, so_long);
	create_player(so_long);
	mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
}

int	exit_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_SUCCESS);
}

int close_w(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit_msg(C_WINDOW);
	return (0);
}
int	key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(so_long->mlx_data.mlx_ptr, so_long->mlx_data.win_ptr);
		exit(0);
	}
	if (keycode == XK_Up || keycode == XK_w)
	{
		if(so_long->map[so_long->player.y - 1][so_long->player.x] != '1')
		{
			so_long->player.y--;
			render_move(so_long);
		}
	}
    if (keycode == XK_Down || keycode == XK_s)
	{
		if(so_long->map[so_long->player.y + 1][so_long->player.x] != '1')
		{
			so_long->player.y++;
			render_move(so_long);
		}
	}
    if (keycode == XK_Right || keycode == XK_d)
	{
		if(so_long->map[so_long->player.y][so_long->player.x + 1] != '1')
		{
			so_long->player.x++;
			render_move(so_long);
		}
	}
    if (keycode == XK_Left || keycode == XK_a)
	{
		if(so_long->map[so_long->player.y][so_long->player.x - 1] != '1')
		{
			so_long->player.x--;
			render_move(so_long);
		}
	}
	return (0);
}
