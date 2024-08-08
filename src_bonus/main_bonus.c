/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:20:58 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/08 20:37:28 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_SUCCESS);
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
