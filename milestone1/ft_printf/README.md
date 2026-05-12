*Este proyecto ha sido creado como parte del currículo de 42 por jruiz-ag.*

# ft_printf 

## Descripción

El objetivo de este proyecto es reimplementar la función printf() de la librería estándar de C (libc). A través de este desafío, he profundizado en el uso de funciones variádicas y en la gestión de diferentes tipos de datos y conversiones en C.La función resultante, ft_printf(), imita el comportamiento del original sin gestionar el búfer, devolviendo el número de caracteres impresos. Este proyecto es una oportunidad crítica para mejorar las habilidades de estructuración de código, ya que la librería final (libftprintf.a) se convertirá en una herramienta reutilizable en futuros proyectos de la formación.🛠️ 

## Instrucciones

### Compilación e Instalación

El proyecto se compila utilizando un Makefile que incluye las flags -Wall -Wextra -Werror y no realiza relink. Para generar la librería:
```make```
Esto creará el archivo libftprintf.a en la raíz del repositorio.

### Uso
Para utilizar la función en tus proyectos, incluye el encabezado correspondiente y vincula la librería al compilar: 

	#include "ft_printf.h"
	int main(void)
	{
		ft_printf("Imprimiendo un número: %d y un hex: %X\n", 42, 42);
		return (0);
	}

Y solo queda compilar junto a la librería estática:  ```cc main.c libftprintf.a```

## Conversiones Soportadas
| Formato | Descripción |
| :--- | :--- |
| `%c` | Imprime un único carácter. |
| `%s` | Imprime una cadena de caracteres (string). |
| `%p` | Imprime un puntero void * en formato hexadecimal. |
| `%d` | Imprime un número decimal (base 10).%iImprime un entero en base 10. | 
| `%u` | Imprime un número decimal (base 10) sin signo. |
| `%x` | Imprime un número hexadecimal (base 16) en minúsculas. |
| `%X` | Imprime un número hexadecimal (base 16) en mayúsculas. |
| `%%` | Imprime el símbolo del porcentaje. |

## Decisiones Técnicas y Algoritmo
Para este proyecto se ha optado por un algoritmo de análisis secuencial asistido por un despachador de funciones (dispatcher):
	
	Iteración: Se recorre la cadena de formato carácter por carácter.
	
	Identificación: Al encontrar un %, se analiza el siguiente carácter para determinar la conversión requerida.
	
	Modularidad: En lugar de un solo bloque de código masivo, se han creado funciones auxiliares para cada tipo de conversión (p. ej., gestión de bases para hexadecimales, tratamiento de punteros y recursividad para números).

## Estructura de Datos
Nos hemos apoyado en las listas opcionales que da la librería <stdarg.h>:	

	Gestión Variádica: Junto con las macros va_start, va_arg y va_end se extraen los argumentos de la pila de forma dinámica, los cuales pueden variar la cantidad en cada ejecución.

Esta estructura permite que el código sea extensible, facilitando la implementación de la parte bonus (flags y anchos de campo) sin comprometer la legibilidad ni la estabilidad de la parte obligatoria.

## Recursos

Manual de printf(3). Para realizar la copia de exacta de la funcionalidad.

Variadic Functions (Programiz). Para comprender el uso de variables opcionales y que van cambiando.

Documentación técnica de stdarg.h. Para saber la implementación interna de estas lista opcionales


## Uso de IA

Se utilizó IA exclusivamente para asistir en la redacción y formateo de este archivo README.md y para clarificar conceptos teóricos sobre la promoción de tipos en argumentos variádicos. No se han solicitado ni copiado soluciones directas de código, garantizando la preparación para los exámenes presenciales donde el acceso a estas herramientas está prohibido.