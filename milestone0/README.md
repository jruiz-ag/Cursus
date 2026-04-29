*Este proyecto ha sido creado como parte del currículo de 42 por <jruiz-ag>.*

# Libft

## Descripción

**Libft** es un proyecto fundamental que consiste en recrear una serie de funciones de la biblioteca estándar de C, además de implementar funciones adicionales que serán reutilizadas en futuros proyectos.

El objetivo principal es comprender en profundidad conceptos clave de programación a bajo nivel, como la gestión de memoria, la manipulación de cadenas, el uso de punteros y el diseño modular del código.

Esta librería se convierte en una herramienta personal que se utilizará a lo largo del cursus de 42.


---

## Instrucciones

### Compilación

Para compilar la librería:

```make```

Esto generará:

```libft.a```

---

### Reglas del Makefile

```
make        # Compila la librería
make clean  # Elimina objetos
make fclean # Elimina objetos y librería
make re     # Recompila todo limpiando primero
```

---


### Uso

Incluye el header en tu código:

```#include "libft.h"```

Compila tu programa con la librería:

```gcc main.c libft.a```

---

## Recursos

Referencias útiles para este proyecto:

* Documentación de la librería estándar de C
* Manuales POSIX (`man`)
* Stack Overflow



### Uso de IA

Se han utilizado herramientas de IA (como ChatGPT) para:

* Aclarar conceptos de programación en C
* Entender el comportamiento de funciones y casos límite
* Mejorar la documentación y estructura del README

Todas las implementaciones han sido desarrolladas y verificadas manualmente para cumplir con las normas de 42.

---

## Funciones de la Librería

Se han implementado funciones nuevas y otras definidas ya en librerías integradas estas son todas:

### Character checks

`ft_isalpha(c)` → 1 si es letra, 0 si no.

`ft_isdigit(c)` → 1 si es número, 0 si no.

`ft_isalnum(c)` → 1 si es letra o número, 0 si no.

`ft_isascii(c)` → 1 si está en ASCII, 0 si no.

`ft_isprint(c)` → 1 si es imprimible, 0 si no.

### Character conversion

`ft_toupper(c)` → carácter en mayúscula (si aplica).

`ft_tolower(c)` → carácter en minúscula (si aplica).

### Memory functions

`ft_memset(ptr, c, n)` → rellena memoria con byte c.

`ft_bzero(ptr, n)` → pone a 0 los bytes.

`ft_memcpy(dst, src, n)` → copia memoria (rompe overlap).

`ft_memmove(dst, src, n)` → copia memoria (protege overlap).

`ft_memchr(ptr, c, n)` → puntero a primer c o NULL.

`ft_memcmp(s1, s2, n)` → diferencia entre bloques.

### Strings

`ft_strlen(s)` → longitud de string.

`ft_strlcpy(dst, src, n)` → copia string, devuelve longitud src.

`ft_strlcat(dst, src, n)` → concatena limitado, devuelve longitud total.

`ft_strchr(s, c)` → puntero a primera aparición.

`ft_strrchr(s, c)` → puntero a última aparición.

`ft_strncmp(s1, s2, n)` → comparación hasta n bytes.

`ft_strnstr(haystack, needle, n)` → busca substring en límite.

### Conversion

`ft_atoi(s)` → string → int.

### Allocation

`ft_calloc(n, size)` → memoria inicializada a 0.

`ft_strdup(s)` → copia dinámica de string.

### Additional functions

`ft_substr(s, start, len)` → substring.

`ft_strjoin(s1, s2)` → concatena strings.

`ft_strtrim(s1, set)` → elimina chars de inicio/fin.

`ft_split(s, c)` → string → array de strings.

`ft_itoa(n)` → int → string.

`ft_strmapi(s, f)` → aplica función → nueva string.

`ft_striteri(s, f)` → aplica función in-place.

### File descriptor output

`ft_putchar_fd(c, fd)` → escribe char.

`ft_putstr_fd(s, fd)` → escribe string.

`ft_putendl_fd(s, fd)` → string + salto de línea.

`ft_putnbr_fd(n, fd)` → escribe número.

### Linked list (t_list).

`ft_lstnew(content)` → crea nodo.

`ft_lstadd_front(lst, new)` → añade al inicio.

`ft_lstsize(lst)` → tamaño lista.

`ft_lstlast(lst)` → último nodo.

`ft_lstadd_back(lst, new)` → añade al final.

`ft_lstdelone(node, del)` → borra nodo.

`ft_lstclear(lst, del)` → borra toda la lista.

`ft_lstiter(lst, f)` → aplica función a cada nodo.

`ft_lstmap(lst, f, del)` → nueva lista transformada.
