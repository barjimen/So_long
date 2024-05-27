/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:16:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/01/25 19:13:32 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	readfile(int fd, char *buffer, char **stack)
{
	int	aux;

	aux = read(fd, buffer, BUFFER_SIZE);
	if (aux < 0 || !buffer)
	{
		if (aux == -1 && *stack)
		{
			free(*stack);
			*stack = NULL;
		}
	}
	else
	{
		buffer[aux] = '\0';
	}
	return (aux);
}

char	*joiny(char *stack, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		aux;
	char	*temp;

	aux = 1;
	while (!ft_strchr(buffer, '\n'))
	{
		aux = readfile(fd, buffer, &stack);
		if (aux <= 0 || !*buffer)
			break ;
		if (stack)
		{
			temp = stack;
			stack = ft_strjoin(temp, buffer);
			free(temp);
		}
		else
		{
			stack = ft_calloc(sizeof(char), aux + 1);
			ft_memcpy(stack, buffer, aux);
		}
	}
	return (stack);
}

char	*clean(char *stack)
{
	int		count;
	int		x;
	char	*tmp;

	x = 0;
	count = 0;
	while ((count == 0 || stack[count - 1] != '\n')
		&& stack[count] != '\0')
		count++;
	if (!stack[count])
	{
		free(stack);
		return (NULL);
	}
	tmp = calloc(sizeof(char), ft_strlen(stack) + 2 - count);
	while (stack[count])
		tmp[x++] = stack[count++];
	free(stack);
	return (tmp);
}

char	*cutty(char **stack)
{
	int		cont;
	char	*line;

	cont = 0;
	while ((*stack)[cont] != '\0' && (*stack)[cont] != '\n')
		cont++;
	line = ft_calloc(sizeof(char), cont + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, *stack, cont + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	line = NULL;
	if (fd != -1 || BUFFER_SIZE > 0 || BUFFER_SIZE < 2147483647)
	{
		stack = joiny(stack, fd);
		if (!stack)
			return (NULL);
		line = cutty(&stack);
		stack = clean(stack);
	}
	return (line);
}
