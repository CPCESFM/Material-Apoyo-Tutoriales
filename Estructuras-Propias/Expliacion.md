# Explicación de los ejercicios de estructuras propias.

### Para Llegar a este punto debiste de haber intentado resolver los ejercicios propuestos:

[Link para Rodillos](https://omegaup.com/arena/problem/Rodillos/#problems)

##  Rodillos OmegaUp

Dado que el valor máximo de rodillos no supera los 1080, podemos resolverlo por "fuerza bruta". Usando la fórmula de distancia entre 
dos puntos, buscaremos para cada rodillo el rodillo que activa, así hasta haber buscado en los `N` rodillos. 

### Entendiendo Código
Construimos la estructura rodillo, la cual tendrá como campos las "coordenadas" de su posición y la longitud de su radio:
```c++
struct rodillo {            
    int x,y,rad;
};
```
Para almacenar la información utilizaremos un arreglo de rodillos `rodillo Rodillos[1081];`. Cuando leamos la información, guardaremos en `actual` el índice del rodillo origen:

```c++
if((Rodillos[i].x == 0)&&(Rodillos[i].y == 0)) actual = i;
```

Para comprobar que un rodillo esta conectado con otro, utilizaremos la fórmula de distancia entre dos puntos y la relación entre los radios:

```c++
bool Estan_conectados(rodillo A, rodillo B){  
    if(sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y)) == A.rad + B.rad ) return true;
    return false;
}
```

Finalmente, utilizaremos un doble ciclo para calcular la respuesta: 
```c++
void resp(){    
    int visitados=1;   
    while(visitados<n){   
        for(int i=1;i<=n;i++){  
            if(Estan_conectados(Rodillos[actual],Rodillos[i])&& (anterior!=i)){
                anterior = actual;  
                actual = i;     
                visitados++;    
                break;          
            }
        }
    }
    cout<<Rodillos[actual].x<<" "<<Rodillos[actual].y;  

}
```
