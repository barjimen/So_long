/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:26:54 by barjimen          #+#    #+#             */
/*   Updated: 2022/09/27 16:04:04 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	a;
	char	*strg;

	a = (char)c;
	strg = (char *)str;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (strg[i] == a)
			return (&strg[i]);
		i--;
	}
	if (strg[i] == a)
		return (&strg[i]);
	return (NULL);
}
