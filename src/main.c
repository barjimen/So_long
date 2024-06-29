/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:26:01 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/29 23:41:05 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
  //mlx_init();
  (void)argc;
  (void)argv;

  t_so_long so_long;
  //int h = 0;
  ft_bzero(&so_long, sizeof(t_so_long));
  arg_handler(argc, argv);
  so_long.map = load_map(argv[1]);
  if (map_check(&so_long))
    exit(1);
  so_long.map = load_map(argv[1]);
  render_map(&so_long);

	printf("%c\n", so_long.map[0][0]);
	printf("%c\n", so_long.map[0][1]);
	printf("%c\n", so_long.map[0][2]);
	printf("%c\n", so_long.map[0][3]);
	printf("%c\n", so_long.map[0][4]);
	printf("%c\n", so_long.map[0][5]);
	printf("%c\n", so_long.map[0][6]);
	
  mlx_key_hook(so_long.mlx_data.win_ptr, key_hook, &so_long.mlx_data);
  mlx_hook(so_long.mlx_data.win_ptr, 17, 0 , close_w, &so_long.mlx_data);
	mlx_loop(so_long.mlx_data.mlx_ptr);
}