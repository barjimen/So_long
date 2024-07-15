/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:28:18 by barjimen          #+#    #+#             */
/*   Updated: 2023/08/23 13:58:30 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(long int nb, char *base)
{
	int				cont;
	unsigned int	nbr;

	cont = 0;
	nbr = 0;
	if (nb < 0)
		nbr += nb;
	else
		nbr = nb;
	if (nbr >= (long int)ft_strlen(base))
	{
		cont += ft_hexa(nbr / ft_strlen(base), base);
		nbr = nbr % ft_strlen(base);
	}
	cont++;
	ft_putchar(base[nbr]);
	return (cont);
}
