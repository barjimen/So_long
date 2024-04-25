/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:32:02 by barjimen          #+#    #+#             */
/*   Updated: 2022/12/28 16:32:54 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*memi;

	memi = (t_list *) malloc(sizeof (t_list));
	if (!memi)
		return (NULL);
	memi->content = content;
	memi->next = NULL;
	return (memi);
}
/*
int	main()
{
	t_list	*prueba;
	prueba = ft_lstnew("hola");
	printf("%s es el contenido\n", prueba->content);
}*/
