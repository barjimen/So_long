/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:39:33 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/09 19:48:15 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	exit_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_SUCCESS);
}

char **save_map(int fd, char **map)
{
	char	*row;
	int		i;
	
	i = 0;
	map = ft_calloc(100 , sizeof(char *));
	row = get_next_line(fd);
	while (row != NULL)
	{
		if (i > 99)
			exit(1);
		map[i] = row;
		row = get_next_line(fd);
		//printf("el fd es despues: %s \n", map[i]);
		i++;
	}
	//printf("el mapita es aqui: %s\n", map[i]);
	free(row);
	return (map);
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
		exit_msg(ARG_KO);
	if (!its_ber(argv[1]))
		exit_msg(NOT_BER); //si no es .ber
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) //si el fd no existe
		exit_msg(FD_0);
	map = save_map(fd, map);
	close(fd);
	return (map);
}