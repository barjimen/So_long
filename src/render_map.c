/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:10:40 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/18 21:01:59 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	exit_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_SUCCESS);
}

void create_map(t_so_long *so_long)
{
	void *img;
	char *path;
	int h;
	int w;
	int he;
	int we;
	
	path = NULL;
	path = "./img/New-Project.xpm";
	he = height_map(so_long->map);
	we = length_map(so_long->map);
	img = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, path, &h, &w);
	if (img == NULL)
		exit_msg(IMG_KO);
	paint_map(we, he, img, so_long);
	mlx_destroy_image(so_long->mlx_data.mlx_ptr, img);

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
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
		
	return (0);
}

void    render_map(t_so_long    *so_long)
{
	
	so_long->mlx_data.mlx_ptr = mlx_init();
	so_long->mlx_data.win_ptr = mlx_new_window(so_long->mlx_data.mlx_ptr, 1920, 1080, "Hello world!");
	create_map(so_long);
	printf("%s\n", so_long->map[0]);
	//if (img == NULL)
		//perror("tpm"); // Comprobar esto :3
	mlx_key_hook(so_long->mlx_data.win_ptr, key_hook, &so_long->mlx_data);
	mlx_hook(so_long->mlx_data.win_ptr, 17, 0 , close_w, &so_long->mlx_data);
	mlx_loop(so_long->mlx_data.mlx_ptr);
	
}