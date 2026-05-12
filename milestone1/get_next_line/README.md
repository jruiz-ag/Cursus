*Este proyecto ha sido creado como parte del currículo de 42 por jruiz-ag.*

# get_next_line

## Descripción
El objetivo de este proyecto es programar una función que devuelva una línea leída de un file descriptor (fd). 
`get_next_line` es un reto fundamental en el currículo de 42 que introduce al estudiante en el manejo de **variables estáticas**, la gestión de memoria dinámica mediante `malloc` y `free`, y la comprensión profunda de cómo el sistema operativo gestiona la lectura de archivos a través de buffers.

Esta versión incluye la parte **bonus**, lo que significa que es capaz de gestionar múltiples file descriptors de manera simultánea sin perder el hilo de lectura de ninguno de ellos.

## Instrucciones

### Compilación
Para utilizar esta función en tu proyecto, debes incluir los archivos fuente y compilar con el flag `-D BUFFER_SIZE=n`, donde `n` es el tamaño del buffer que desees.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

## Ejecución

Si deseas probar la función con un archivo de texto:

Crea un archivo main.c que llame a get_next_line en un bucle iterativo, hasta que reciba un puntero de string a NULL.

Ya tienes unos main.c incluidos por si quieres probar la lectura de un archivo o de varios de forma simultánea. Solo tendrías que incluir los main*.c dentro de la carpeta /test.

## ⚠️ Advertencia sobre Gestión de Memoria

Es importante tener en cuenta que get_next_line reserva memoria dinámicamente utilizando malloc para cada línea que devuelve. Es responsabilidad exclusiva del programador que utiliza la función liberar (free) la memoria de cada línea devuelta para evitar fugas de memoria (memory leaks).

## Algoritmo y Decisiones Técnicas

El algoritmo de get_next_line se basa en una estrategia de lectura acumulativa:

    Buffer de lectura: Se utiliza un buffer temporal de tamaño BUFFER_SIZE para leer del archivo mediante la función read().

    Variable Estática (Almacén): La clave del proyecto es una variable static char *. Esta variable actúa como una "memoria persistente" entre llamadas a la función. En ella se concatena lo leído hasta encontrar un carácter de salto de línea (\n) o el final del archivo (EOF).

    Extracción: Una vez que el almacén contiene un \n, el algoritmo divide la cadena:

        La parte anterior al \n (incluyéndolo) se devuelve como la línea actual.

        La parte posterior se guarda nuevamente en la variable estática para la siguiente llamada.

    Gestión del Bonus (Múltiples FD): Para el bonus, la variable estática se convierte en un array de punteros (o una estructura similar), permitiendo que cada índice del array corresponda a un file descriptor diferente. Esto evita que la lectura del fd 3 interfiera con la del fd 4.

## Justificación

Se eligió este enfoque por su eficiencia en el uso de memoria. Al procesar solo lo necesario y mantener el resto en una variable estática, minimizamos las llamadas al sistema read(), que son costosas en términos de rendimiento, y aseguramos que no haya fugas de memoria (memory leaks) mediante un control estricto de los punteros.

## Recursos

Documentación de la función read: man read(2). Fue un apoyo fundamental para comprender que devolvía el número de bytes que se leían con éxito para copiar únicamente los bytes leídos con éxito.

Entendiendo las Variables Estáticas en C. Clave para comprender como conservan el estado entre llamadas a la función.

Gestión de memoria y punteros en C. Base del proyecto cubriendo en todo momento cualquier fuga posible de memoria.

## Uso de IA

Para este proyecto, se ha utilizado IA (como ChatGPT/Gemini) de la siguiente manera:

Redacción de este README: La IA desarrolló de manera extensa este README ayudando con la presentación y haciendola más estética. 

Optimización: No se utilizó IA para la generación directa de código, sino para validar la lógica del algoritmo de guardado del "sobrante" (leaks prevention).


---
