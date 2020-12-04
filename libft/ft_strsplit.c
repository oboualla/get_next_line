/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 00:01:01 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/19 13:56:03 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		**ft_remplir(char **tab, char *s, char c)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = -1;
	j = 0;
	if (s == NULL)
		return (0);
	while (s[++i])
	{
		if (s[i] != c && flag == 0)
		{
			if (!(tab[j] = (char *)malloc(sizeof(char) *
							(ft_wordlen(s, c) + 1))))
				return (NULL);
			tab[j] = ft_strccpy(tab[j], s + i, c);
			j++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	char		*src;

	src = (char *)s;
	if (!(src))
		return (0);
	if (!(tab = (char**)malloc(sizeof(char *) * (ft_count_word(src, c) + 1))))
		return (0);
	ft_remplir(tab, src, c);
	return (tab);
}
