/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:06:53 by oboualla          #+#    #+#             */
/*   Updated: 2019/04/18 18:44:03 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		while (((char *)list->content)[i])
		{
			write(1, &list->content[i], 1);
			i++;
		}
		list = list->next;
	}
}
