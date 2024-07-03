/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:26:47 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/03 22:22:05 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	//move_handler(keycode, so_long);
	if (keycode == XK_Up || keycode == XK_w)
	{
        printf("felcha arriba\n");
		if(so_long->map[so_long->player.y - 1][so_long->player.x] != '1')
		{
			so_long->player.y--;
			so_long->player.player_moves++;
			printf("El personaje esta en: [%d][%d]\nY se ha movido %d veces\n", so_long->player.y, so_long->player.x, so_long->player.player_moves);
			item_removed(so_long);
			map_iter_context(so_long->map, create_background, so_long);
			//so_long->map[so_long->player.y][so_long->player.x] = 'P';
			map_iter_context(so_long->map, create_items, so_long);
			create_player(so_long);
			mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
		}
	}
    if (keycode == XK_Down || keycode == XK_s)
	{
        printf("felcha abajo\n");
		

		if(so_long->map[so_long->player.y + 1][so_long->player.x] != '1')
		{
			so_long->player.y++;
			so_long->player.player_moves++;
			printf("El personaje esta en: [%d][%d]\nY se ha movido %d veces\n", so_long->player.y, so_long->player.x, so_long->player.player_moves);
			item_removed(so_long);
			map_iter_context(so_long->map, create_background, so_long);
			//so_long->map[so_long->player.y][so_long->player.x] = 'P';
			map_iter_context(so_long->map, create_items, so_long);
			create_player(so_long);
			/*put_img_to_img(so_long->mlx_data.img,
				so_long->mlx_data.sprites[PLAYER],
				(W_SIZE / 2 - so_long->map_w / 2) + so_long->player.x * 32 ,
				(H_SIZE / 4 - so_long->map_h / 2) + so_long->player.y * 16 - 16 * so_long->player.x);*/
			mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
		}
	}
    if (keycode == XK_Right || keycode == XK_d)
	{
        printf("felcha drch\n");
		
		if(so_long->map[so_long->player.y][so_long->player.x + 1] != '1')
		{
			so_long->player.x++;
			so_long->player.player_moves++;
			printf("El personaje esta en: [%d][%d]\nY se ha movido %d veces\n", so_long->player.y, so_long->player.x, so_long->player.player_moves);
			item_removed(so_long);
			map_iter_context(so_long->map, create_background, so_long);
			//so_long->map[so_long->player.y][so_long->player.x] = 'P';
			map_iter_context(so_long->map, create_items, so_long);
			create_player(so_long);
			mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
		}
	}
    if (keycode == XK_Left || keycode == XK_a)
	{
		printf("felcha izq\n");
		
		if(so_long->map[so_long->player.y][so_long->player.x - 1] != '1')
		{
			so_long->player.x--;
			so_long->player.player_moves++;
			printf("El personaje esta en: [%d][%d]\nY se ha movido %d veces\n", so_long->player.y, so_long->player.x, so_long->player.player_moves);
			item_removed(so_long);
			map_iter_context(so_long->map, create_background, so_long);
			//so_long->map[so_long->player.y][so_long->player.x] = 'P';
			map_iter_context(so_long->map, create_items, so_long);
			create_player(so_long);
			mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
		}
	}
	
	return (0);
}