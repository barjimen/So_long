/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset_calculator_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:28:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/09 21:53:11 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	window_size_calculator(t_so_long *so_long)
{
	so_long->window_w = (so_long->map_w * 64) + (so_long->map_h * 64);
	so_long->window_h = (so_long->map_w * 35) + (so_long->map_h * 35);
	if (so_long->window_w >= MAX_WIN_W)
		exit_msg(WIDTH_MAX_ERROR);
	if (so_long->window_h >= MAX_WIN_H)
		exit_msg(HEIGHT_MAX_ERROR);
}

void	offset_calculator(t_so_long *so_long)
{
	so_long->w_offset = ((so_long->window_w / 2 - 64)
			- (32 * (so_long->map_w - so_long->map_h)));
	so_long->h_offset = ((so_long->window_h / 2)
			- (32 * ((so_long->map_w + so_long->map_h) / 2)) - 64);
}
