/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_end_with.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:20:47 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/28 00:38:48 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_str_end_with(const char *str, const char *end)
{
	int	len_a;
    int len_b;

	len_a = ft_strlen(str);
	len_b = ft_strlen(end);

	if (len_b > len_a)
        return (0);
	while (len_b > 0)
	{
		if (str[len_a] != end[len_b])
			return (0);
		len_a--;
		len_b--;
	}
	return (1);
}