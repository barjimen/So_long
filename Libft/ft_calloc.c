/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:21:24 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/05 20:01:05 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*a;
	size_t	b;
	size_t	c;

	b = count * size;
	a = (char *) malloc(b);
	if (b < size && b < count)
	{
		return (NULL);
	}
	if (a != NULL)
	{
		c = 0;
		while (c < b)
		{
			a[c] = '\0';
			c++;
		}
	}
	return ((void *)a);
}
