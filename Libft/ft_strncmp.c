/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:01:26 by barjimen          #+#    #+#             */
/*   Updated: 2022/09/29 18:24:24 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	x;

	x = 0;
	while ((s1[x] != '\0' || s2[x] != '\0') && x < n)
	{
		if ((unsigned char)s1[x] > (unsigned char)s2[x])
			return (1);
		else if ((unsigned char)s1[x] < (unsigned char)s2[x])
			return (-1);
		x++;
	}
	return (0);
}
