/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_end_with_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:20:47 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/09 21:49:22 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_str_end_with(const char *str, const char *end)
{
	int	len_a;
	int	len_b;

	len_a = ft_strlen(str);
	len_b = ft_strlen(end);
	if (len_b > len_a)
		return (0);
	while (len_b > 0)
	{
		if (str[len_a] != end[len_b])
			return (0);
		len_a--;
		len_b--;
	}
	return (1);
}

void	item_removed(t_so_long *so_long)
{
	if (so_long->map[so_long->player.y][so_long->player.x] == 'C')
	{
		so_long->player.collect_num++;
		ft_printf("You have collect: %d\n",
			so_long->player.collect_num);
		so_long->map[so_long->player.y][so_long->player.x] = '0';
	}
	if (so_long->player.collect_num == so_long->maps.c
		&& so_long->map[so_long->player.y][so_long->player.x] == 'E')
	{
		ft_printf("Moves: %d \n", so_long->player.player_moves);
		mlx_destroy_window(so_long->mlx_data.mlx_ptr,
			so_long->mlx_data.win_ptr);
		exit_msg(WIN);
	}
	if (so_long->map[so_long->player.y][so_long->player.x] == 'X')
	{
		mlx_destroy_window(so_long->mlx_data.mlx_ptr,
			so_long->mlx_data.win_ptr);
		exit_msg(DEAD);
	}
}
