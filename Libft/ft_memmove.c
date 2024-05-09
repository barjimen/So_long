/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:11:13 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/06 20:22:23 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*a;
	const char	*b;

	a = (char *)dst;
	b = (const char *)src;
	i = 0;
	if (!b && !a)
		return (NULL);
	if (dst > src)
	{
		while (len--)
			a[len] = b[len];
	}
	else
	{
		while (i < len && a != b)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (a);
}
