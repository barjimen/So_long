/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:44:11 by barjimen          #+#    #+#             */
/*   Updated: 2022/10/23 18:40:47 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	a;
	size_t	c;
	char	*b;

	if (!s || !f)
		return (NULL);
	a = 0;
	c = ft_strlen(s);
	b = ft_calloc(c + 1, sizeof(char));
	if (!b)
		return (NULL);
	while (s[a])
	{
		b[a] = f(a, s[a]);
		a++;
	}
	return (b);
}
