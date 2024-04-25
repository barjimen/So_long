/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:52:31 by barjimen          #+#    #+#             */
/*   Updated: 2022/09/28 17:35:47 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	b;
	unsigned char	*str;

	str = (unsigned char *) s;
	b = (unsigned char ) c;
	a = 0;
	while (n)
	{
		if (str[a] == b)
			return ((void *) &str[a]);
		a++;
		n--;
	}
	return (NULL);
}
