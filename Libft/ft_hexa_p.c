/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:38:12 by barjimen          #+#    #+#             */
/*   Updated: 2023/08/23 13:58:55 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_p(unsigned long int nb, char *base)
{
	int	cont;

	cont = 0;
	if (nb >= (unsigned long int)ft_strlen(base))
	{
		cont += ft_hexa_p(nb / ft_strlen(base), base);
		nb = nb % ft_strlen(base);
	}
	cont++;
	ft_putchar(base[nb]);
	return (cont);
}
