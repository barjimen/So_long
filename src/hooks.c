/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:26:47 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/28 00:13:49 by barjimen         ###   ########.fr       */
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
int	key_hook(int keycode, t_data *mlx)
{
	(void)mlx;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
		
	return (0);
}