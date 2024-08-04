/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:20:58 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/04 22:15:34 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_SUCCESS);
}

int	hook_animate(void *data)
{
	t_so_long *so_long = (t_so_long *)data;
	so_long->time++;
	if (so_long->time & 16384 && !(so_long->player.x == so_long->e_pos.x && so_long->player.y == so_long->e_pos.y))
	{
		if (so_long->player.collect_num == so_long->maps.c)
			create_anim(so_long, &so_long->exit_open,so_long->w_offset + so_long->e_pos.x * 64 - (64 * so_long->e_pos.y), so_long->h_offset + so_long->e_pos.y * 32 + (32 * so_long->e_pos.x));
		else
			create_anim(so_long, &so_long->exit_close,so_long->w_offset + so_long->e_pos.x * 64 - (64 * so_long->e_pos.y), so_long->h_offset + so_long->e_pos.y * 32 + (32 * so_long->e_pos.x));
		mlx_put_image_to_window(so_long->mlx_data.mlx_ptr, so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
		put_text(so_long);
		so_long->time = 0;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	t_so_long	so_long;

	(void)argc;
	(void)argv;
	check_all_img();
	ft_bzero(&so_long, sizeof(t_so_long));
	arg_handler(argc, argv);
	so_long.map = load_map(argv[1]);
	if (map_check(&so_long))
		exit(1);
	so_long.map = load_map(argv[1]);
	offset_calculator(&so_long);
	render_map(&so_long);
	mlx_loop_hook(so_long.mlx_data.mlx_ptr, hook_animate, &so_long);
	mlx_key_hook(so_long.mlx_data.win_ptr, key_hook, &so_long);
	mlx_hook(so_long.mlx_data.win_ptr, 17, 0, close_w, &so_long.mlx_data);
	mlx_loop(so_long.mlx_data.mlx_ptr);
}
