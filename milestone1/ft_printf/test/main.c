#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int			cont;
	const char	*s = "---> BYTES ESCRITOS:";


	ft_printf("\n--- PRUEBAS %%c %%s ---\n\n");
	
	cont = ft_printf("Mi amigo: %s, Dice que %c%c", "JUAN", 'N', 'a');
	printf("   %s %d\n", s, cont);
	cont = printf("Mi amigo: %s, Dice que %c%c", "JUAN", 'N', 'a');
	printf("   %s %d\n\n", s, cont);


	ft_printf("\n--- PRUEBAS %%p ---\n\n");
	
	cont = ft_printf("La direccion del polo es: %p", s);
	printf("   %s %d\n", s, cont);
	cont = printf("La direccion del polo es: %p", s);
	printf("   %s %d\n\n", s, cont);
	cont = ft_printf("NULL %p NULL", NULL);
	printf("%s %d\n", s, cont);
	cont = printf("NULL %p NULL", NULL);
	printf("%s %d\n\n", s, cont);


	ft_printf("\n--- PRUEBAS NULL ---\n\n");

	cont = ft_printf(NULL);
	printf("%s %d\n", s, cont);
	cont = printf(NULL);
	printf("%s %d\n\n", s, cont);
	cont = ft_printf("NULL %s NULL", NULL);
	printf("%s %d\n", s, cont);
	cont = printf("NULL %s NULL", NULL);
	printf("%s %d\n\n", s, cont);


	ft_printf("\n--- PRUEBAS %%d %%i ---\n\n");

	cont = ft_printf("Estoy con %d o %i de money. Tengo %d perros, y %i gatos", -2132, -44, 2, 3);
	printf("   %s %d\n", s, cont);
	cont = printf("Estoy con %d o %i de money. Tengo %d perros, y %i gatos", -2132, -44, 2, 3);
	printf("   %s %d\n\n", s, cont);


	ft_printf("\n--- PRUEBAS %%u ---\n\n");

	cont = ft_printf("%u %u", -232132, 6549);
	printf("   %s %d\n", s, cont);
	cont = printf("%u %u", -232132, 6549);
	printf("   %s %d\n\n", s, cont);


	ft_printf("\n--- PRUEBAS %%x %%X ---\n\n");

	cont = ft_printf("%x %x %X %X", -232132, 6549, -232132, 6549);
	printf("   %s %d\n", s, cont);
	cont = printf("%x %x %X %X", -232132, 6549, -232132, 6549);
	printf("   %s %d\n\n", s, cont);

	#include <limits.h>
	cont = ft_printf("%p %p", LONG_MIN, LONG_MAX);
	printf("   %s %d\n", s, cont);
	cont = printf("%p %p", LONG_MIN, LONG_MAX);
	printf("   %s %d\n\n", s, cont);

}