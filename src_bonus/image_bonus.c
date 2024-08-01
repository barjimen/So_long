/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:43:09 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/15 22:34:21 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.width && y < img.height)
	{
		dst = img.addr + (y * img.line_length + x * (img.bppx / 8));
		*(unsigned int *) dst = color;
	}
}

t_img	create_image(void *mlx, int width, int height)
{
	t_img	image;

	image.ptr = mlx_new_image(mlx, width, height);
	image.width = width;
	image.height = height;
	image.addr = mlx_get_data_addr(image.ptr, &image.bppx,
			&image.line_length, &image.endian);
	return (image);
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.line_length) + (x * img.bppx / 8))));
}

void	put_img_to_img(t_img dst, t_img src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.width)
	{
		j = 0;
		while (j < src.height)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

t_img	load_xpm(void *mlx, char *path)
{
	t_img	image;

	image.ptr = mlx_xpm_file_to_image(mlx, path,
			&image.width, &image.height);
	image.addr = mlx_get_data_addr(image.ptr, &image.bppx,
			&image.line_length, &image.endian);
	return (image);
}
