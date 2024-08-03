/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:18:26 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/03 15:54:47 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	create_enemy(void	*data, int x, int y)
{
    t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'X')
		put_img_to_img(so_long->mlx_data.img,
			so_long->mlx_data.sprites[ENEMY],
			so_long->w_offset + x * 64 - (64 * y),
			so_long->h_offset + y * 32 + (32 * x));
}

int img_exist(char *img)
{
    int i;

    i = open(img, O_RDONLY);
    if (i == -1)
        return (0);
    close(i);
    return (1);
}

int check_all_img(void)
{
    if (!img_exist(FLOOR_SRC) || !img_exist(ROOMBA_SRC_UP)
        || !img_exist(ROOMBA_SRC_DWN) || !img_exist(ROOMBA_SRC_LFT)
        || !img_exist(ROOMBA_SRC_RHT) || !img_exist(WALLS_SRC)
        || !img_exist(EXIT_KO_SRC) || !img_exist(EXIT_OK_SRC)
        || !img_exist(COLLECT_SRC) || !img_exist(COVER_SRC))
        return (exit_msg(IMG_KO));
    return (1);
}