*Este proyecto ha sido creado como parte del currículo de 42 por jruiz-ag, lupin.*

# push_swap_v2

## Descripción

`push_swap_v2` es una solución al proyecto `push_swap` de 42. El objetivo es ordenar una lista de enteros usando solo dos pilas, `a` y `b`, y un conjunto muy limitado de operaciones: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb` y `rrr`.

Este repositorio no se limita a una única estrategia de ordenación. En su lugar, implementa varios algoritmos y un modo adaptativo que selecciona el enfoque más razonable según el tamaño y el nivel de desorden de la entrada. El proyecto también incluye un ejecutable bonus, `checker`, para validar secuencias de movimientos.

## Instrucciones

### Compilación

Desde la raíz del proyecto:

```bash
make
```

Esto compila el binario principal `push_swap` y la librería local `libft`.

Para compilar el bonus:

```bash
make bonus
```

### Ejecución

El programa recibe la lista de números como argumentos separados o como una única cadena:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

También admite banderas para forzar una estrategia concreta o activar el modo de benchmark:

```bash
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
./push_swap --bench --adaptive 4 67 3 87 23
```

### Checker

El bonus `checker` verifica si la secuencia de operaciones deja la pila ordenada:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Algunos ejemplos de uso habituales:

```bash
./push_swap 2 1 3
./push_swap --adaptive 9 1 8 2 7 3 6 4 5
./push_swap --bench --complex 10 9 8 7 6 5 4 3 2 1
```

### Limpieza

```bash
make clean
make fclean
make re
```

## Algoritmos y justificación

La elección de algoritmos responde a una idea práctica: no existe una única estrategia óptima para todas las entradas en `push_swap`. El coste real no se mide por tiempo de CPU, sino por la cantidad de operaciones generadas. Por eso este proyecto combina varias técnicas y selecciona la más adecuada según el caso.

### 1. Ordenación pequeña: `small_sort`

Para listas de 2 a 5 elementos se usa una ruta especial pensada para minimizar el número de movimientos.

En esta rama se aplican soluciones directas:

- 2 elementos: un `sa` si hace falta.
- 3 elementos: una secuencia corta de swaps y rotaciones.
- 4 elementos: se reutiliza `insertion_sort`.
- 5 elementos: se extraen los dos mínimos, se ordena el resto con la lógica de 3 elementos y se devuelven los valores extraídos.

Justificación: en entradas pequeñas, cualquier algoritmo más general introduce sobrecoste innecesario. Una solución específica reduce operaciones y simplifica el caso crítico donde el margen de mejora es mayor.

### 2. `insertion_sort`

Esta estrategia construye la pila ordenada en `b` e inserta cada nuevo elemento en la posición correcta, usando rotaciones para colocar el punto de inserción y luego `pb` / `pa` para mover elementos entre pilas.

Justificación: es una solución natural para tamaños reducidos o medianos con coste de implementación bajo. Aunque su complejidad es peor que la de `radix_sort`, ofrece un comportamiento predecible y un número de operaciones razonable cuando la entrada no es grande. En determinadas casuísticas, esta estrategia reduce el coste práctico desde $O(n^2)$ hacia $O(n)$ al aprovechar mejor la posición relativa de los elementos.

### 3. `chunk_sort`

`chunk_sort` primero normaliza la lista asignando a cada nodo un índice relativo a su posición en el orden ascendente. Después divide el rango en bloques de tamaño aproximado `sqrt(n)` y va empujando elementos a `b` por chunks. Una vez vaciada `a`, devuelve los valores a `a` en orden descendente, buscando siempre el máximo de `b`.

Justificación: el enfoque por bloques reduce el coste frente a estrategias puramente locales. El uso de `sqrt(n)` equilibra la cantidad de bloques y el coste de buscar el siguiente elemento, lo que suele dar un compromiso sólido para listas medianas. Se eligió junto con `radix_sort` porque ambos trabajan sobre índices, lo que simplifica la implementación y unifica la lógica de ordenación.

### 4. `radix_sort`

`radix_sort` también trabaja sobre índices normalizados, no sobre los valores originales. Después recorre los bits necesarios del índice más grande y, en cada pasada, separa elementos según el bit actual: los que tienen `0` pasan a `b` y los que tienen `1` rotan en `a`. Al final de cada pasada, devuelve todo desde `b` a `a`.

Justificación: esta técnica es muy estable para entradas grandes porque evita comparaciones entre pares y mantiene una complejidad previsible. En `push_swap`, donde lo importante es controlar el número de operaciones, esta regularidad es especialmente útil para listas amplias y muy desordenadas. Igual que `chunk_sort`, su uso sobre índices facilita bastante la implementación.

### 5. Modo adaptativo

El modo `--adaptive` calcula un índice de desorden basado en el número de parejas invertidas respecto al total de parejas posibles:

$$
\text{disorder} = \frac{\text{inversiones}}{\text{pares totales}}
$$

Con ese valor, el programa decide:

- `disorder < 0.2`: estrategia simple.
- `0.2 <= disorder < 0.5`: estrategia intermedia (`chunk_sort`).
- `disorder >= 0.5`: estrategia compleja (`radix_sort`).

Además, para listas de 5 elementos o menos, el flujo adaptativo deriva directamente a `small_sort`.

Justificación: esta heurística evita usar una estrategia costosa cuando la lista ya está relativamente cerca de su estado final, y reserva `radix_sort` para los casos donde el desorden hace que el enfoque por bits sea más rentable.

## Recursos

### Referencias clásicas

- Documentación oficial de 42 sobre `push_swap` y `checker`.
- `man` de `make`, `gcc` y herramientas estándar de Unix.
- Conceptos de estructuras enlazadas y pilas en C.
- Artículos y tutoriales sobre `push_swap`, `radix sort`, `insertion sort` y estrategias basadas en chunks.
- Explicaciones sobre inversiones y métricas de desorden en secuencias ordenables.

### Uso de IA

Se ha utilizado IA como apoyo para:

- redactar y reorganizar la documentación del proyecto,
- revisar la claridad de las explicaciones técnicas,
- proponer una estructura de README más legible para una audiencia externa,
- resumir el comportamiento de los algoritmos a partir de la implementación existente.

No se ha utilizado IA para sustituir la lógica central del proyecto ni para generar las implementaciones de los algoritmos.

## Contribuciones

- jruiz-ag: control de la entrada y parseo, y los algoritmos `chunk_sort`, `radix_sort` y `small_sort`.
- lupin: manejo del espacio de trabajo, funciones de listas enlazadas, `insertion_sort` y parte del bonus.
- Trabajo compartido: desarrollo de movimientos, definición del bonus, `Makefile`, pruebas y documentación.

## Características adicionales

- Parser de argumentos con validación de rangos y duplicados.
- Salida de error homogénea mediante `Error\n` ante entradas inválidas.
- Librería local `libft` integrada en el propio repositorio.
- Bonus `checker` para comprobar secuencias de operaciones.

En modo `--bench`, el programa imprime métricas a `stderr`, incluyendo el índice de desorden, la estrategia elegida y el recuento de operaciones utilizadas.