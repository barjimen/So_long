/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:28:00 by barjimen          #+#    #+#             */
/*   Updated: 2024/03/05 20:01:47 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contp(char const *str, char delim)
{
	int	contpal;
	int	contstr;

	contpal = 0;
	contstr = 0;
	while (str[contstr])
	{
		if (str[contstr] != delim && (str[contstr + 1] == delim
				|| str[contstr + 1] == '\0'))
			contpal++;
		contstr++;
	}
	return (contpal);
}

static int	contl(char const *str, char delim, int strp)
{
	int	strl;

	strl = 0;
	while (str[strp] != delim && str[strp])
	{
		strl++;
		strp++;
	}
	return (strl);
}

static void	*ft_free(char **strs, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
		free(strs[i++]);
	free(strs[i]);
	return (NULL);
}

static char	**ft_end(char const *s, char c, int cont, char **strs)
{
	int	a;
	int	b;
	int	posstr;
	int	lnstr;

	posstr = 0;
	b = 0;
	while (b < cont)
	{
		while (s[posstr] == c)
			posstr++;
		a = 0;
		lnstr = contl(s, c, posstr);
		strs[b] = ft_calloc((lnstr + 1), sizeof(char));
		if (!strs)
			return (ft_free(strs, cont));
		while (lnstr--)
		{
			strs[b][a++] = s[posstr++];
		}
		b++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		cont;
	char	**strs;

	if (!s)
		return (NULL);
	cont = contp(s, c);
	strs = ft_calloc((cont + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	return (ft_end(s, c, cont, strs));
}
