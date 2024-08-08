/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_or_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:59:32 by barjimen          #+#    #+#             */
/*   Updated: 2024/08/08 23:38:15 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_or_x(char x, unsigned long int nb)
{
	if (x == 'x')
		return (ft_hexa(nb, "0123456789abcdef"));
	else if (x == 'X')
		return (ft_hexa(nb, "0123456789ABCDEF"));
	return (0);
}
