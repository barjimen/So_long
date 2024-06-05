/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:13:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/01/11 19:35:10 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	str_size;
	size_t	i;

	str_size = count * size;
	str = malloc(str_size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < str_size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

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

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
