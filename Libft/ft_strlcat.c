/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:35:22 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/05 19:59:46 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dtsize)
{
	unsigned int	x;
	unsigned int	ldes;
	unsigned int	lsou;
	unsigned int	y;

	x = 0;
	if (!dst && !dtsize)
		return ((size_t) NULL);
	ldes = ft_strlen(dst);
	lsou = ft_strlen(src);
	if (dtsize == 0 || dtsize <= ldes)
		return (lsou + dtsize);
	y = ldes;
	while (src[x] && ldes + x < dtsize - 1)
	{
		dst[y] = src[x];
		x++;
		y++;
	}
	dst[y] = '\0';
	return (ldes + lsou);
}
