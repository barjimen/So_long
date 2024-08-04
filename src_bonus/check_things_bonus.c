/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:18:26 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/04 21:03:11 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	images_load(t_so_long *so_long, t_anim *anim, char *file, int frames)
{
	int		i;
	int		len;

	anim->max = frames;
	len = ft_strlen(file) + 1;
	anim->file = malloc(sizeof(char) * (len));
	ft_strlcpy(anim->file, file, len);
	anim->images = malloc(sizeof(t_img) * (frames + 1));
	i = -1;
	while (++i <= frames)
	{
		anim->file[len - 6] = '0' + i % 10;
		anim->file[len - 7] = '0' + i / 10;
		anim->images[i] = load_xpm(so_long->mlx_data.mlx_ptr,
				anim->file);
	}
}

void create_anim(t_so_long *so_long, t_anim *anim, int x, int y)
{
    printf("%d", anim->frame);
    put_img_to_img(so_long->mlx_data.img,
		anim->images[anim->frame], x, y);
	if (anim->frame < anim->max)
		anim->frame++;
	else
		anim->frame = 0;
}

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