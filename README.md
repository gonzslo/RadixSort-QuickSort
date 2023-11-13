# RadixSort-QuickSort

### Profesores:
- Benjamín Bustos
- Gonzalo Navarro

### Estudiantes
- Gonzalo Cisternas
- Javiera Jiménez
- Daniela Moraga

### Requerimientos
* C++
* Compilador
En caso de no tener esto, seguir los pasos de [esta página](https://code.visualstudio.com/docs/cpp/config-mingw).

### Archivos importantes
Los archivos **QuickSort.hpp** y **RadixSort.hpp** contienen los algoritmos correspondientes para ordenar arreglos de tamaño SIZE. Las instrucciones de creación de arreglos y su ordenamiento utilizando estos algoritmos, se encuentran en el archivo **test.cpp**, que importa los archivos mencionados anteriormente y ejecuta todo en un main. Además tiene definidas algunas funciones auxiliares necesarias para la ejecución.

### Paso a paso
Una vez que se tienen los requerimientos, basta con ejecutar **test.cpp**, lo cual creará 100 arreglos de tamaño igual a 1millón junto con una copia de cada uno, universo por universo, partiendo desde el universo 2^1 hasta 2^63. Para cada universo, se irá guardando el tiempo que demoró en ordenarse cada uno de los 100 arreglos creados utilizando Radix Sort y el tiempo que demoró utilizando Quick Sort en archivos de texto con los nombres universo1.txt, universo2.txt, ..., universo63.txt, para luego poder utilizar estos datos para generar visualizaciones gráficas de las diferencias temporales entre ambos algoritmos.
