/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:05:57 by barjimen          #+#    #+#             */
/*   Updated: 2022/11/19 16:10:18 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	b;

	b = ft_strlen(s1);
	a = malloc((sizeof(char)) * b + 1);
	if (!a)
		return (NULL);
	b = 0;
	while (s1[b])
	{
		a[b] = s1[b];
		b++;
	}
	a[b] = '\0';
	return (a);
}
