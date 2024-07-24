/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:18:26 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/24 21:01:21 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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