/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:56:24 by barjimen          #+#    #+#             */
/*   Updated: 2022/11/19 16:38:44 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		m;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	m = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_calloc(m + 1, sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[a])
	{
		s3[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		s3[a++] = s2[b++];
	}
	s3[a] = '\0';
	return (s3);
}
