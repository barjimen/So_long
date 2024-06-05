/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:36:24 by barjimen          #+#    #+#             */
/*   Updated: 2024/04/28 23:20:53 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int handle_no_event(void *data)
{
	data = NULL;
	return (0);
}

int window_killer(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int handle_input(int keysnm, t_data *data)
{
	(void)data;
	//printf("Keycode es: %i\n", keysnm);
	if (keysnm == 65307)
		window_killer(data);
	return (0);
}

int main(void)
{
	t_data data;
 
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "hi :)");
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_hook(data.win_ptr, 17, 0, window_killer, &data);
	mlx_loop(data.mlx_ptr);
}