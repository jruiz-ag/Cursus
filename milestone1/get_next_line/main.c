#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int		fd;
	char	*res;
	int		cont;

	fd = open("quijote", O_RDONLY);
	if (fd < 1)
		return (-1);
	cont = 0;
	while(cont < 5)
	{ 
		res = get_next_line(fd);
		if (res)
		{
			printf("%s", res);
			free(res);
		}
		else
			printf("\nNulo");
		++cont;
	}
}