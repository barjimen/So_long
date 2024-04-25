/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:31:02 by barjimen          #+#    #+#             */
/*   Updated: 2022/12/28 16:33:01 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstaux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lstaux = ft_lstlast(*lst);
	lstaux->next = new;
}
