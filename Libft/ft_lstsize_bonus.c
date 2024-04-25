/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:32:12 by barjimen          #+#    #+#             */
/*   Updated: 2022/11/20 20:33:05 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cont;
	t_list	*lstaux;

	if (!lst)
		return (0);
	lstaux = lst;
	cont = 1;
	while (lstaux->next != NULL)
	{
		cont++;
		lstaux = lstaux->next;
	}
	return (cont);
}
