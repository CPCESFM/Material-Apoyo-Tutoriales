#include <bits/stdc++.h>

using namespace std;

struct rodillo {            //Declaramos la estructura rodillo
    int x,y,rad;
};

rodillo Rodillos[1100];        //Declaramos un arreglo de rodillos para guardar la información
int n;      //Declaramos las variables globales que vamos a utilizar
int anterior,actual;      //"anterior" y "actual" indican las respectivas posiciones de los rodillos visitados o activados

void leer(){        //Declaramos una función que lee la información
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>Rodillos[i].x>>Rodillos[i].y>>Rodillos[i].rad;
        if((Rodillos[i].x == 0)&&(Rodillos[i].y == 0)) actual = i; //Guardamos la posición del rodillo origen
    }
}

bool Estan_conectados(rodillo A, rodillo B){  //Declaramos una función que calcula si los rodillos están conectados
    if(sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y)) == A.rad + B.rad ) return true;
    return false;
}

void resp(){    //Declaramos la función que calcula la respuesta
    int visitados=1;    //Variable local que cuenta el número de rodillos visitados o activados
    while(visitados<n){     //el proceso termina cuando todos los rodillos están activados o visitados
        for(int i=1;i<=n;i++){  //Para el rodillo actual, se buscará al rodillo que activa
            //El rodillo que activa es el que está conectado (Usamos la funcion "Estan_conectados") y además es distinto del anterior:
            if(Estan_conectados(Rodillos[actual],Rodillos[i])&& (anterior!=i)){
                anterior = actual;  //ahora el anterior pasa a ser el actual
                actual = i;     //El actual pasa a ser el rodillo encontrado
                visitados++;    //aumentamos el numero de rodillos activados
                break;          //Rompemos el for, pues ya no es necesario buscar en los demás
            }
        }
    }
    cout<<Rodillos[actual].x<<" "<<Rodillos[actual].y;  //Mostramos la posición del último rodillo activado

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    leer();     //Finalmente, llamamos ambas funciones
    resp();

    return 0;
}
