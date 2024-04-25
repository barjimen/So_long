/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:00:49 by barjimen          #+#    #+#             */
/*   Updated: 2022/10/23 18:41:16 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*a;
	const char	*b;

	a = (char *)dst;
	b = (const char *)src;
	i = 0;
	if (b == '\0' && a == '\0')
		return (NULL);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
