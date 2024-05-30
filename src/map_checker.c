/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:13:57 by barjimen          #+#    #+#             */
/*   Updated: 2024/05/30 18:56:47 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int length_map(char **map)
{
	int i;
	int length1;
	int length2;
	

	i = 0;
	length1 = 0;
	length2 = 0;
	while (map[i])
	{
		length1 = ft_strlen(map[i]);
		printf("%d mide: %d\n", i, length1);
		length2 = ft_strlen(map[i++]);
		printf("%d mide: %d\n", i, length2);
		if (length1 != length2 || length1 == '\0' || length1 == '\0')
			{
				printf("salí\n");
				exit(1);
			}
		i++;
	}
	
	return (0);
}

char *map_check(char **map)
{
	length_map(map);
	return (0);
}