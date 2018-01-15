#include "get_next_line.h"

int		gnl(int fd, char **line)
{
	int i;

	i = 0;
	if (BUFFSIZE < 0 || fd < 0 || (!line))
		return (FALSE);
//	printf("1");
	*line = ft_strdup("");
//	printf("%zi", read(fd, line, BUFFSIZE));
	if ((read(fd, line, BUFFSIZE)) == 1)
		{
			printf("1");
			printf("%s\n", *line);
			return (1);
		}
	return (0);
 }
