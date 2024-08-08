/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:36:31 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/08 23:30:01 by barjimen         ###   ########.fr       */
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

void	create_anim(t_so_long *so_long, t_anim *anim, int x, int y)
{
	put_img_to_img(so_long->mlx_data.img,
		anim->images[anim->frame], x, y);
	if (anim->frame < anim->max)
		anim->frame++;
	else
		anim->frame = 0;
}

int	hook_animate(void *data)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)data;
	so_long->time++;
	if (so_long->time & 16384 && !(so_long->player.x == so_long->e_pos.x
			&& so_long->player.y == so_long->e_pos.y))
	{
		if (so_long->player.collect_num == so_long->maps.c)
			create_anim(so_long, &so_long->exit_open, so_long->w_offset
				+ so_long->e_pos.x * 64 - (64 * so_long->e_pos.y),
				so_long->h_offset + so_long->e_pos.y * 32
				+ (32 * so_long->e_pos.x));
		else
			create_anim(so_long, &so_long->exit_close, so_long->w_offset
				+ so_long->e_pos.x * 64 - (64 * so_long->e_pos.y),
				so_long->h_offset + so_long->e_pos.y * 32
				+ (32 * so_long->e_pos.x));
		mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,
			so_long->mlx_data.win_ptr, so_long->mlx_data.img.ptr, 0, 0);
		put_text(so_long);
		so_long->time = 0;
	}
	return (1);
}
