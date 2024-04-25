/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:09:39 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/05 20:01:21 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(long n)
{
	size_t	numb;

	numb = 0;
	if (n < 0)
	{
		n *= -1;
		numb++;
	}
	while (n > 9)
	{
		numb++;
		n /= 10;
	}
	return (numb);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*m;
	size_t	digits;

	nb = (long)n;
	digits = count(nb);
	m = ft_calloc(digits + 2, sizeof(char));
	if (!m)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		m[0] = '-';
	}
	if (nb == 0)
		m[0] = '0';
	while (nb > 0)
	{
		m[digits] = (nb % 10) + 48;
		nb /= 10;
		digits--;
	}
	return (m);
}
