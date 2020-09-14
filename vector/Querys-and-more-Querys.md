# Solución al problema de Querys and more Querys 

Se seleccionó este problema ya que permite ver que en gran parte el uso de vector y arreglos es un poco más de preferencia que de obligación, pero mucho 
**cuidado**, siempre ten en cuenta el costo en tiempo que representa usar vectores. Con esto en mente, se nos pide que determinemos cuantas veces aparece un 
valor dentro de un rango **relativamente comedido**, a priori podría venir a tu mente usar una búsqueda binaria para encontrar estos valores, pero existe 
una solción mucho más óptima. 

Primero haremos uso de una `cubeta`, que puede venir en dos presentación por nos tomaremos la libertad de escribir ambas. 
+ Vector

```C++
vector<int> vcubeta;
```

+Arreglo

```C++
int acubeta[1000000];
```

