#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int		fd;
	char	*res;

	fd = open("texto", O_RDONLY);
	if (fd < 1)
		return (-1);
	res = get_next_line(fd);
	printf("%s", res);
	free(res);
	close(fd);
}