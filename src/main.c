/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:36:24 by barjimen          #+#    #+#             */
/*   Updated: 2024/04/28 23:20:53 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(void)
{
    printf("hola\n");
    void *mlx_ptr;
	void *win_ptr;
 
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hi :)");
    mlx_loop(mlx_ptr);
	if (!win_ptr)
		return (free(mlx_ptr), 1);
	free(mlx_ptr);
	return (0);
}