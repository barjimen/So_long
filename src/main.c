/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:26:01 by barjimen          #+#    #+#             */
/*   Updated: 2024/05/27 22:37:38 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
    char **mapita;
    int i = 0;
    
    mapita = NULL;
    arg_handler(argc, argv, &mapita);
    //while (mapita[i] != NULL)
	//	printf("%s", mapita[i++]);
    printf("\nFIN\n");
    //if (map_check(mapa))
    //    exit()
    //render_map(mapita); 
}