/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:38:45 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/01 22:05:28 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int keycode_handler(int keycode,t_so_long so_long)
{
    if (keycode == 65362)
        printf("felcha arriba\n");
    else if (keycode == 65364)
        printf("felcha abajo\n");
    else if (keycode == 65363)
        printf("felcha drch\n");
    else if (keycode == 65361)
        printf("felcha izq\n");
    
    return (0);
}

void move_handler(int keycode, t_so_long so_long)
{
    keycode_handler(keycode, so_long);
}
