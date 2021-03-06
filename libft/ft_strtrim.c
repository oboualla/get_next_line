/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 01:53:02 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/19 14:02:18 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int			i;
	char		*str;
	int			j;
	int			k;

	k = 0;
	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_count_char(s) + 1)))
		return (NULL);
	j = ft_fkj_back(s, " \n\t");
	i = ft_fkj(s, " \n\t");
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
