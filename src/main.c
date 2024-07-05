/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:26:01 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/05 21:17:49 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  t_so_long so_long;
  ft_bzero(&so_long, sizeof(t_so_long));
  arg_handler(argc, argv);
  so_long.map = load_map(argv[1]);
  if (map_check(&so_long))
    exit(1);
  so_long.map = load_map(argv[1]);
  render_map(&so_long);
  mlx_key_hook(so_long.mlx_data.win_ptr, key_hook, &so_long);
  mlx_hook(so_long.mlx_data.win_ptr, 17, 0 , close_w, &so_long.mlx_data);
	mlx_loop(so_long.mlx_data.mlx_ptr);
}
