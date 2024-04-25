/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:02:58 by barjimen          #+#    #+#             */
/*   Updated: 2022/11/19 16:28:51 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*b;

	if (!s)
		return (NULL);
	a = ft_strlen(s);
	if (start >= a)
	{
		b = ft_calloc(1, 1);
		if (!b)
			return (NULL);
		return (b);
	}
	if (len > a)
		len = a - start;
	b = ft_calloc (sizeof(char), len + 1);
	if (!b)
		return (NULL);
	b = ft_memcpy(b, &s[start], len);
	return (b);
}
