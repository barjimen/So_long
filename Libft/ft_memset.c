/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:56:01 by barjimen          #+#    #+#             */
/*   Updated: 2022/09/21 12:23:50 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*i;
	int		cont;

	cont = 0;
	i = (char *)b;
	while (len)
	{
		i[cont] = c;
		cont++;
		len--;
	}
	return ((void *)i);
}
