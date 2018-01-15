#ifndef get_next_line
# define get_next_line

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define BUFFSIZE 1

# include "../libft/libft.h"


int		gnl(int const fd, char **line);

#endif