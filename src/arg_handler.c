/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:39:33 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/28 00:47:30 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int file_lines(char *path)
{
	int fd;
	char *row;
	int i;
	
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0) //si el fd no existe
		exit_msg(FD_0);
	row = get_next_line(fd);
	while (row != NULL)
	{
		free(row);
		row = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}
char **load_map(char *path)
{
	int 	fd;
	char	*row;
	int		i;
	char 	**map;

	i = 0;
	map = ft_calloc(file_lines(path) + 1 , sizeof(char *));
	fd = open(path, O_RDONLY);
	if (fd < 0) //si el fd no existe
		exit_msg(FD_0);
	row = get_next_line(fd);
	while (row != NULL)
	{
		map[i] = row;
		row = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	arg_handler(int argc, char **argv)
{
	if (argc != 2)
		exit_msg(ARG_KO);
	if (!ft_str_end_with(argv[1], ".ber"))
		exit_msg(NOT_BER);
}