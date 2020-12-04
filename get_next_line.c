/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:12:30 by oboualla          #+#    #+#             */
/*   Updated: 2019/05/15 23:12:55 by oboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_is_separ(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

static int	ft_cache_new_line(char **line, char **cach)
{
	int			i;
	char		*str;

	i = 0;
	if (!(line) || !(*line))
		return (-1);
	str = ft_strdup(*line);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	ft_strdel(&*line);
	if (str[i] == '\0')
	{
		*line = ft_strdup(str);
		ft_strdel(&str);
		return (1);
	}
	str[i] = '\0';
	*line = ft_strdup(str);
	*cach = ft_strdup(&str[i + 1]);
	ft_strdel(&str);
	return (1);
}

static int	read_fd(int fd, char **str, int flag)
{
	int		nbread;
	int		s;
	char	*ptr;
	char	*buff;

	s = 0;
	nbread = 0;
	buff = ft_strnew(BUFF_SIZE);
	if (flag == 0 || flag == 1)
		while ((nbread = read(fd, buff, BUFF_SIZE)) != 0)
		{
			if (nbread == -1)
				return (-1);
			ptr = *str;
			*str = ft_strjoin(*str, buff);
			ft_strdel(&ptr);
			s++;
			if (ft_is_separ(*str, '\n'))
				break ;
			ft_memset((void*)buff, 0, BUFF_SIZE);
		}
	ft_strdel(&buff);
	if (nbread == 0 && s == 0 && flag == 0)
		return (0);
	return (1);
}

static int	ft_move_cash(char **str, char **cash)
{
	char *tmp;

	if (!(cash) || !(*cash))
		return (-1);
	if (*cash[0] == '\0')
	{
		ft_strdel(&*cash);
		return (0);
	}
	tmp = *str;
	*str = ft_strdup(*cash);
	ft_strdel(&tmp);
	ft_strdel(&*cash);
	if (ft_is_separ(*str, '\n') == 1)
		return (2);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char				*cash[4097] = {NULL};
	char					*str;
	int						flag;

	flag = 0;
	if ((!line) || BUFF_SIZE < 0 || (read(fd, NULL, 0) == -1) || fd > 4096)
		return (-1);
	if (!(str = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (cash[fd])
		flag = ft_move_cash(&str, &cash[fd]);
	if (flag == 0 || flag == 1)
		flag = read_fd(fd, &str, flag);
	ft_cache_new_line(&str, &cash[fd]);
	if (flag != 0 && flag != -1)
		*line = ft_strdup(str);
	ft_strdel(&str);
	if (flag == 0 || flag == -1)
		return (flag);
	return (1);
}
