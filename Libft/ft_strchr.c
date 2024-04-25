/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:10:02 by barjimen          #+#    #+#             */
/*   Updated: 2022/09/28 14:44:03 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	a;
	char	*strg;

	a = (char)c;
	strg = (char *)str;
	i = 0;
	while (strg[i])
	{
		if (strg[i] == a)
			return (&strg[i]);
		i++;
	}
	if (strg[i] == a)
		return (&strg[i]);
	return (NULL);
}
