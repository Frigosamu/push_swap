# DESCRIPCIÓN

push_swap es un proyecto cuyo objetivo es ordenar una lista de números enteros utilizando dos stacks (a y b) y un conjunto limitado de operaciones (sa, pb, ra, etc.).

El reto principal consiste en encontrar la forma más eficiente posible de ordenar los números, minimizando el número de movimientos realizados.

El proyecto incluye diferentes estrategias de ordenación según el tamaño del stack:
algoritmos simples para pocos números,
algoritmos por chunks para tamaños intermedios,
algoritmo radix para grandes cantidades de datos.

# INSTRUCCIONES

Compilación
make
Ejecución

```
./push_swap 3 2 1 5 4 
 ```

También es posible seleccionar manualmente el algoritmo:

```
./push_swap --simple 3 2 1
./push_swap --medium 5 8 1 9 2
./push_swap --complex 10 4 7 2 1
```

Opcionalmente, puede utilizarse:

```
--bench
```

para recopilar estadísticas de movimientos.

# RECURSOS

Referencias utilizadas
Documentación oficial de C
Manual de operaciones de push_swap
Explicaciones sobre algoritmos Radix Sort
Recursos sobre listas doblemente enlazadas y manipulación de stacks
Videos y artículos sobre estrategias de optimización en push_swap
Uso de IA

Se ha utilizado IA como apoyo para:

Comprensión y depuración de algoritmos.
Explicación de estructuras y lógica.
Optimización y refactorización de funciones.
Resolución de errores y validaciones.
Ayuda en la documentación del proyecto (Readme).

La implementación, adaptación y validación final del código han sido realizadas manualmente durante el desarrollo del proyecto.

# DETALLES DEL PROYECTO Y JUSTIFICACIÓN DE USO
## 1. Justificación de los valores límite (Umbrales)
El índice de desorden se calcula con ft_compute_disorder, que mide cuántos números están fuera de orden comparado con el máximo posible.
Para ello cuenta las inversiones (pares de números mal colocados)
las divide entre el número total de pares posibles.
Así obtiene un valor entre:
0 → lista completamente ordenada
1 → lista completamente desordenada.

### Régimen Bajo (< 0.2)
Un valor menor que 0.2 significa que el stack está casi ordenado y solo hay unos pocos números fuera de sitio.
Usar algoritmos grandes aquí haría movimientos innecesarios.

### Régimen Medio (0.2 ≤ desorden < 0.5)
El stack tiene un desorden intermedio.
En este caso conviene dividir los números en bloques para reducir rotaciones y ordenar de forma más eficiente.

### Régimen Alto (≥ 0.5)
El stack está muy desordenado o casi invertido.
Aquí se necesita un algoritmo más automático y estable, que funcione bien sin importar el orden inicial.
---

## 2. Análisis de las Técnicas Internas y Complejidad

### 🟢 Régimen Bajo: ft_simple (Adaptación del orden por inserción)

**Descripción:**
Cuando el stack está casi ordenado, el algoritmo detecta los elementos fuera de sitio, los mueve temporalmente a B y luego los reinserta en la posición correcta dentro de A.
Como la mayoría de números ya están bien colocados, se necesitan pocas operaciones.

**Complejidad Temporal (Peor caso):** O(n)
El número de movimientos crece de forma aproximadamente lineal, ya que hay pocos elementos desordenados.

**Complejidad Espacial:** O(1)
No utiliza memoria extra significativa, trabaja directamente sobre los stacks existentes.
---

### 🟡 Régimen Medio: ft_medium (uso de chunks)

**Descripción:**
El algoritmo divide los números en bloques (“chunks”) para ordenar el stack de forma más eficiente.
Primero asigna un índice a cada elemento y después mueve a B los números que pertenecen al bloque actual. El tamaño de esos bloques se adapta según el tamaño del stack.
Una vez todos los elementos están en B, se devuelven a A buscando siempre el valor más grande y usando la rotación más corta (rb o rrb).

**Complejidad Temporal (Peor caso):** O(n \sqrt{n})
Dividir el stack en bloques reduce el número de búsquedas y rotaciones necesarias durante la ordenación.

**Complejidad Espacial:** $O(n)$
Necesita memoria extra para almacenar temporalmente los índices usados durante el preprocesado del stack.

---

### 🔴 Régimen Alto: ft_complex_radix (Radix Sort Binario por Bits)

**Descripción:**
Este algoritmo ordena los números usando su representación en binario.
En cada pasada revisa un bit concreto, empezando por el menos significativo:
si el bit es 0, el número se mueve a B
si el bit es 1, el número permanece en A
Después los elementos de B vuelven a A y el proceso se repite con el siguiente bit.
Como funciona bit a bit, el rendimiento es estable incluso cuando el stack está completamente desordenado.

**Complejidad Temporal (Peor caso):** O(nlogn)
El algoritmo hace varias pasadas sobre el stack, aproximadamente una por cada bit necesario para representar los índices.

**Complejidad Espacial:** O(n)
Necesita memoria adicional durante la fase de indexación inicial de los elementos.
