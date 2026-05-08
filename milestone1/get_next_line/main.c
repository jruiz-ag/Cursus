#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int		fd;
	char	*res;
	int		cont;

	fd = open("quijote", O_RDONLY);
	res = get_next_line(fd);
	cont = 0;
	while(cont < 5)
	{ 
		if (res)
		{
			printf("%s", res);
			free(res);
		}
		else
			printf("\nNulo");
		res = get_next_line(fd);
		++cont;
	}
}