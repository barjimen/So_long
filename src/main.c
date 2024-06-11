/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:26:01 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/11 22:26:07 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
  //mlx_init();
  t_so_long so_long;
  char **mapita;
  char **mapita_copy;
  //int h = 0;
    
  mapita = NULL;
  mapita_copy = NULL;
  mapita = arg_handler(argc, argv, mapita);
  mapita_copy = arg_handler(argc, argv, mapita_copy);
  if (map_check(mapita_copy))
    exit(1);
  so_long.map = mapita;

  //printf("ESTE ES EL MAPA A IMPRIMIR\n");
	/*while (mapita[h])
	{
		printf("%s", mapita[h]);
		h++;
	}*/
  render_map(&so_long);
  exit(0);
}