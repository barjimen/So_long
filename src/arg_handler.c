/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:39:33 by barjimen          #+#    #+#             */
/*   Updated: 2024/05/27 22:36:51 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void save_map(int fd, char ***map)
{
	//char 	**map;
	char	*row;
	int		i;
	
	i = 0;
	//map = NULL;
	map = ft_calloc(100, sizeof(char *));
	row = get_next_line(fd);
	while (row != NULL)
	{
		if (i > 99)
			exit(1);
		map[i] = &row;
		free(row);
		row = get_next_line(fd);
		i++;
	}
	free(row);
	i = 0;
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

void arg_handler(int argc, char **argv, char ***map)
{
	int fd;
	
	
	if (argc != 2)
		exit(1);
	if (!its_ber(argv[1]))
		exit(1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	save_map(fd, map);
	close(fd);
}