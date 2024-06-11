/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:10:40 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/11 22:37:32 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void create_map(t_so_long *so_long)
{
	char **img;
	char *path;
	int h;
	int w;
	int he;
	int we;
	
	path = NULL;
	path = "./img/New-Project.xpm";
	he = height_map(so_long->map);
	we = length_map(so_long->map);
	while (we)
	{
		while (he)
		{
			img = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, path, &h, &w);
			mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, img, he * 50, we * 50);
			we--;
		}
		we = length_map(so_long->map);
		he--;
	}
	
}

static int	exit_msg(char *msg)
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
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
		
	return (0);
}

void    render_map(t_so_long    *so_long)
{
	//char **img;
	//char *path;
	//int h = 200;
	//int w = 200;
	//path = NULL;
	//path = "./img/New-Project.xpm";
	
	so_long->mlx_data.mlx_ptr = mlx_init();
	so_long->mlx_data.win_ptr = mlx_new_window(so_long->mlx_data.mlx_ptr, 1920, 1080, "Hello world!");
	//so_long->mlx_data.img.img = mlx_new_image(so_long->mlx_data.mlx_ptr, 640,480);
	//img = mlx_new_image(so_long->mlx_data.mlx_ptr, 200, 200);
	create_map(so_long);
	//img = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, path, &h + 100, &w);
	
	//if (img == NULL)
		//perror("tpm"); // Comprobar esto :3
	//mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, img, 0, 0); //error :(
	mlx_key_hook(so_long->mlx_data.win_ptr, key_hook, &so_long->mlx_data);
	mlx_hook(so_long->mlx_data.win_ptr, 17, 0 , close_w, &so_long->mlx_data);
	mlx_loop(so_long->mlx_data.mlx_ptr);
	
}