#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int main()
{
	char texto[] = "Hola";
	char tex1[] = "coso";
	ft_memcpy(tex1, texto, 1);
	printf("%s", tex1);
}