#include "get_next_line.h"

int		gnl(int fd, char **line)
{
	int i;
	char *buf;
	char *temp;
	char *joinend;

	i = 0;
	if (BUFFSIZE < 0 || fd < 0 || (!line))
		return (FALSE);
	buf = ft_strnew(BUFFSIZE);
	temp = ft_strdup("");
	while (read(fd, buf, BUFFSIZE))
		{
		//	printf("%s", buf);
			if (!(*line = ft_strchr(buf, '\n')))
			{
				temp = ft_strjoin(temp, buf);
				printf("NU JE AAAÂ");
			}
			else
			{
				temp = ft_strjoin(temp, ft_strsub(buf, 0, ft_strchrlen(buf, '\n')));
				joinend = ft_strsub(buf, ft_strchrlen(buf, '\n') + 1, BUFFSIZE - ft_strchrlen(buf, '\n')); 
			}
			printf("temp : %s\n", temp);
			printf("join : %s\n", joinend);
		}

	return (0);
 }
