/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:28:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/30 23:54:29 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    offset_calculator(t_so_long *so_long)
{
    so_long->w_offset = ((W_SIZE / 2 - 64) - (32 * (so_long->map_w - so_long->map_h)));
    so_long->h_offset = ((H_SIZE / 2) - (32 * ((so_long->map_w + so_long->map_h)/2)) - 64);
}