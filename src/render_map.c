/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:10:40 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/09 00:10:50 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_data *vars)
{
    (void)vars;
	keycode  = printf("Hello from key_hook!\n");
	return (0);
}

void    render_map(t_so_long    *so_long)
{
	so_long->mlx_data.mlx_ptr = mlx_init();
	so_long->mlx_data.win_ptr = mlx_new_window(so_long->mlx_data.mlx_ptr, 640, 480, "Hello world!");
	mlx_key_hook(so_long->mlx_data.win_ptr, key_hook, &so_long);
	mlx_loop(so_long->mlx_data.mlx_ptr);
}