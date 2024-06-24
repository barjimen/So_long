/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:56:41 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/24 22:39:06 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	pixel_put(t_img *img, int x_offset, int y_offset, int color)
{
	char	*dst;

	if (x_offset < 0 || x_offset >= 1920 || y_offset < 0 || y_offset >= 1080)
		return ;
	dst = img->addr + (y_offset * img->line_length + x_offset
			* (img->bppx / 8));
	*(unsigned int *)dst = color;
}

void    put_pixel_to_image(t_img *img, int x, int y, int color)
{
    int     i;

    if (x >= 0 && x < img->width && y >= 0 && y < img->height)
    {
        i = (x * img->bppx / 8) + (y * img->line_length);
        img->addr[i] = color;
        img->addr[++i] = color >> 8;
        img->addr[++i] = color >> 16;
        img->addr[++i] = color >> 24;
    }
}


unsigned int get_pixel_color(t_img *img, int x, int y)
{
    int i;
    unsigned int color;

    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return (0);
    i = (x * img->bppx / 8) + (y * img->line_length);
    color = *(unsigned int *)(img->addr + i);
    return (color);
}

void fill_image_with_color(t_img *img, int color)
{
    int x, y;

    y = 0;
    while (y < img->height)
    {
        x = 0;
        while (x < img->width)
        {
            put_pixel_to_image(img, x, y, color);
            x++;
        }
        y++;
    }
}

void    draw_images(t_so_long *so_long)
{
    int x, y;
    unsigned int color2;

    y = 0;
    while (y < so_long->mlx_data.img1.height)
    {
        x = 0;
        while (x < so_long->mlx_data.img1.width)
        {
            color2 = get_pixel_color(&so_long->mlx_data.img2, x, y);

            // Assuming color2's alpha is 0x00 for full transparency
            if ((color2 & 0xFF000000) != 0x00000000)
            {
                put_pixel_to_image(&so_long->mlx_data.img1, x, y, color2);
            }
            x++;
        }
        y++;
    }
}



void paint_map(int width, int height, char *img, t_so_long *so_long)
{
    (void)width;
    (void)height;
    (void)img;

    char *f_path;
   
    f_path = "./img/sea.xpm";
  //  so_long->mlx_data.img.img = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, f_path, &so_long->mlx_data.img.width, &so_long->mlx_data.img.height);
  //  so_long->mlx_data.img.addr = mlx_get_data_addr(so_long->mlx_data.img.img, &so_long->mlx_data.img.bppx, &so_long->mlx_data.img.line_length, &so_long->mlx_data.img.endian);
    so_long->mlx_data.img.img = mlx_new_image(so_long->mlx_data.mlx_ptr, 800, 600);
    so_long->mlx_data.img.addr = mlx_get_data_addr(so_long->mlx_data.img.img, &so_long->mlx_data.img.bppx, &so_long->mlx_data.img.line_length, &so_long->mlx_data.img.endian);
    //fill_image_with_color(so_long->mlx_data.img.img, 7);
    pixel_put(so_long->mlx_data.img.img, 100, 100, 0xFF0000);
    mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, so_long->mlx_data.img.img, 0, 0);
    
    so_long->mlx_data.img1.img = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, "./img/circle2.xpm", &so_long->mlx_data.img1.width, &so_long->mlx_data.img1.height);
    so_long->mlx_data.img1.addr = mlx_get_data_addr(so_long->mlx_data.img1.img, &so_long->mlx_data.img1.bppx, &so_long->mlx_data.img1.line_length, &so_long->mlx_data.img1.endian);

    so_long->mlx_data.img2.img = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, "./img/circle2.xpm", &so_long->mlx_data.img2.width, &so_long->mlx_data.img2.height);
    so_long->mlx_data.img2.addr = mlx_get_data_addr(so_long->mlx_data.img2.img, &so_long->mlx_data.img2.bppx, &so_long->mlx_data.img2.line_length, &so_long->mlx_data.img2.endian);


    draw_images(so_long);
   
    mlx_put_image_to_window(so_long->mlx_data.mlx_ptr, so_long->mlx_data.win_ptr, so_long->mlx_data.img1.img, 0, 0);
}

/*void paint_map(int width, int height, char *img, t_so_long *so_long)
{
    void *floor;
    char *f_path;
    int h;
	int w;
    void *p;

    h = 0;
    w = 0;
    f_path = "./img/sea.xpm";
    floor = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, f_path, &h, &w);
    p = mlx_xpm_file_to_image(so_long->mlx_data.mlx_ptr, "./img/circle2.xpm", &h, &w);
    while (height)
	{
		while (width)
		{
            if(so_long->map[height - 1][width - 1] != '1')
                mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, floor, width * 50, height * 50);
            else if (so_long->map[height - 1][width - 1] != '0')
			    mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, img, width * 50, height * 50);
			//if(so_long->map[height - 1][width - 1] != '0' && so_long->map[height - 1][width - 1] != '1')
                //mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, p, width * 50, height * 50);
            if(so_long->map[height - 1][width - 1] == 'P')
                mlx_put_image_to_window(so_long->mlx_data.mlx_ptr,so_long->mlx_data.win_ptr, p, width * 50, height * 50);
            width--;
		}
		width = length_map(so_long->map);
		height--;
	}
    mlx_destroy_image(so_long->mlx_data.mlx_ptr, floor);
    mlx_destroy_image(so_long->mlx_data.mlx_ptr, p);
}*/