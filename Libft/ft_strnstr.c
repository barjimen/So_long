/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:58:41 by barjimen          #+#    #+#             */
/*   Updated: 2022/11/19 16:21:17 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[a] && a < len)
	{
		b = 0;
		while (haystack[a + b] == needle[b] && (a + b) < len)
		{
			if (haystack[a + b] == '\0' && needle[b] == '\0')
				return ((char *)&haystack[a]);
			b++;
		}
		if (needle[b] == '\0')
			return ((char *)&haystack[a]);
		a++;
	}
	return (NULL);
}
