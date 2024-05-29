/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:39:33 by barjimen          #+#    #+#             */
/*   Updated: 2024/05/29 20:53:17 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char **save_map(int fd, char **map)
{
	//char 	**map;
	char	*row;
	int		i;
	
	i = 0;
	//map = NULL;
	
	map = ft_calloc(10 , sizeof(char *));
	row = get_next_line(fd);
	//printf("el fd es: %s \n", row);
	//printf("el i es despues: %d \n", i);
	while (row != NULL)
	{
		if (i > 99)
			exit(1);
		map[i] = row;
		row = get_next_line(fd);
		printf("el fd es despues: %s \n", map[i]);
		i++;
	}
	printf("el mapita es aqui: %s\n", map[i]);
	free(row);
	return map;
}

int	its_ber(char *argv)
{
	int	i;

	i = 0;
	i = ft_strlen(argv);
	if (i < 5)
		return (0);
	return ((argv[i - 1] == 'r') && (argv[i - 2] == 'e')
		&& (argv[i - 3] == 'b') && (argv[i - 4] == '.'));
}

char	**arg_handler(int argc, char **argv, char **map)
{
	int fd;
	
	
	if (argc != 2)
		exit(1);
	if (!its_ber(argv[1]))
		exit(1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	map = save_map(fd, map);
	printf("el mapita es pp: %s\n", map[1]);
	close(fd);
	return (map);
}