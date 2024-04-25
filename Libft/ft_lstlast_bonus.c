/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:31:45 by barjimen          #+#    #+#             */
/*   Updated: 2022/12/28 16:33:11 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lstaux;

	if (!lst)
		return (NULL);
	lstaux = lst;
	while (lstaux->next != NULL)
		lstaux = lstaux->next;
	return (lstaux);
}
