/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:49:00 by barjimen          #+#    #+#             */
/*   Updated: 2023/08/23 13:58:36 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point(void *nb)
{
	unsigned long int	a;
	int					count;

	count = 0;
	a = (unsigned long int)nb;
	write(1, "0x", 2);
	count += (ft_hexa_p(a, "0123456789abcdef") + 2);
	return (count);
}
