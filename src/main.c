/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:26:01 by barjimen          #+#    #+#             */
/*   Updated: 2024/05/29 20:55:53 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
    char **mapita;
   // int i = 0;
    
    mapita = NULL;
    mapita = arg_handler(argc, argv, mapita);
     printf("mapita es en main: %s\n", mapita[1]);
    //if (mapita)
        //printf("mapita 0 es: %s", mapita[0]);
    //while (mapita[i] != NULL)
		//("%s", mapita[i++]);
    printf("\nFIN\n");
    //if (map_check(mapa))
    //    exit()
    //render_map(mapita);
    exit(0);
}