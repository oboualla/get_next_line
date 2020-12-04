/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fkj_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:43:36 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/18 18:49:35 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fkj_back(char const *str, char *sp)
{
	int i;
	int count;
	int j;

	count = 0;
	i = ft_strlen(str) - 1;
	count = ft_strlen(str) - 1;
	if (str)
		while (str[i])
		{
			j = 0;
			while (sp[j])
			{
				if (str[count] == sp[j])
					count--;
				j++;
			}
			i--;
		}
	return (count);
}
