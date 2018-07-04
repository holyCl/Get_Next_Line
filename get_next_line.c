/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:01:39 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/01/24 15:01:44 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char					*split_parts(char *buf, char **data)
{
	char				*tmp;

	tmp = *data;
	*data = ft_strjoin(*data, buf);
	ft_strdel(&tmp);
	return (*data);
}

static	char				*parse_line(char *str)
{
	int					len;
	char				*tmp;
	int					i;

	i = -1;
	len = ft_strlen(str);
	tmp = malloc(sizeof(char) * len + 1);
	while (str[++i] != '\n' && len--)
		tmp[i] = str[i];
	tmp[i] = '\0';
	return (tmp);
}

static char					*clear(char *str)
{
	char	*tmp;
	int		i;

	i = -1;
	while (str[++i] != '\n' && str[i])
		;
	tmp = ft_strdup(str + i + 1);
	ft_strdel(&str);
	return (tmp);
}

int							get_next_line(const int fd, char **line)
{
	static	t_gnl			size[1200];
	int						rb;
	char					buf[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 0 || !line || read(fd, 0, 0) == -1)
		return (-1);
	if (size[fd].str == NULL)
		size[fd].str = ft_strnew(1);
	rb = 1;
	while (!(ft_strchr(size[fd].str, '\n')))
	{
		if ((rb = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[rb] = '\0';
		size[fd].str = split_parts(buf, &(size[fd].str));
		if (rb == FALSE)
			break ;
	}
	if (*(size[fd].str) == '\0')
		return (0);
	*line = parse_line(size[fd].str);
	size[fd].str = clear(size[fd].str);
	return (1);
}
