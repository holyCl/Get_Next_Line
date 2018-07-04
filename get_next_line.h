/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:00:48 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/01/24 15:00:53 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# include "libft/libft.h"
# include <fcntl.h>

typedef	struct		s_gnl
{
	int				fd;
	char			*str;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
