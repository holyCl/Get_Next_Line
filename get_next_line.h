#ifndef get_next_line
# define get_next_line

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define BUFFSIZE 32

# include "../libft/libft.h"


int		gnl(int const fd, char **line);
int		ft_strchrlen(const char *s, int c);

#endif