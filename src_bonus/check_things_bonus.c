/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:18:26 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/09 21:54:13 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	create_cover(void *data, int sprite_type)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	put_img_to_img(so_long->mlx_data.img,
		so_long->mlx_data.sprites[sprite_type], so_long->w_offset
		+ so_long->player.x * 64 - (64 * so_long->player.y), so_long->h_offset
		+ so_long->player.y * 32 + (32 * so_long->player.x));
}

void	create_enemy(void *data, int x, int y)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	if (so_long->map[y][x] == 'X')
		put_img_to_img(so_long->mlx_data.img, so_long->mlx_data.sprites[ENEMY],
			so_long->w_offset + x * 64 - (64 * y), so_long->h_offset + y * 32
			+ (32 * x));
}

int	img_exist(char *img)
{
	int	i;

	i = open(img, O_RDONLY);
	if (i == -1)
		exit_msg(IMG_KO);
	close(i);
	return (1);
}

void	anim_img(void)
{
	const char	*files_close[] = {
		"./img/exit/red/00.xpm", "./img/exit/red/01.xpm",
		"./img/exit/red/02.xpm", "./img/exit/red/03.xpm",
		"./img/exit/red/04.xpm", "./img/exit/red/05.xpm",
		"./img/exit/red/06.xpm", "./img/exit/red/07.xpm"};
	const char	*files_open[] = {
		"./img/exit/00.xpm", "./img/exit/01.xpm",
		"./img/exit/02.xpm", "./img/exit/03.xpm",
		"./img/exit/04.xpm", "./img/exit/05.xpm",
		"./img/exit/06.xpm", "./img/exit/07.xpm"};
	int			i;

	i = 0;
	while (i < 8)
	{
		img_exist((char *)files_close[i]);
		img_exist((char *)files_open[i]);
		i++;
	}
}

int	check_all_img(void)
{
	if (!img_exist(FLOOR_SRC) || !img_exist(ROOMBA_SRC_UP)
		|| !img_exist(ROOMBA_SRC_DWN) || !img_exist(ROOMBA_SRC_LFT)
		|| !img_exist(ROOMBA_SRC_RHT) || !img_exist(WALLS_SRC)
		|| !img_exist(EXIT_KO_SRC) || !img_exist(EXIT_OK_SRC)
		|| !img_exist(COLLECT_SRC) || !img_exist(COVER_SRC))
		return (exit_msg(IMG_KO));
	anim_img();
	return (1);
}
