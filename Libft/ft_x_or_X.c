/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_or_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:59:32 by barjimen          #+#    #+#             */
/*   Updated: 2023/08/22 00:28:31 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_x_or_X(char x, unsigned long int nb)
{
	//printf("%ld es nb en x or x\n",nb);
	if (x == 'x')
		return (ft_hexa(nb, "0123456789abcdef"));
	else if (x == 'X')
		return (ft_hexa(nb, "0123456789ABCDEF"));
	return (0);
}
