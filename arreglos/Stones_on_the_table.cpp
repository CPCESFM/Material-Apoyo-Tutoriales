#include <bits/stdc++.h>
using namespace std;
///Declaramos un arreglo de tipo caracter con el maximo numero de piedras
char piedra[52];
int n;

//Funcion que calculas cuantas piedras remover
int calcula() {
    ///Creamos una variable para retornar la respuesta
    int respuesta=0;
    ///Creamos una variable para ir avanzando en el arreglo de piedras
    int i=1;
    ///Mientras aun estemos recorriendo las piedras ...
    while(i<=n) {
        ///Guardamos el color de la piedra actual
        char color=piedra[i];
        ///Contamos piedras del mismo color para eliminarlas (incluyendo la actual)
        ///Las vamos contando con otra variable
        int mismo_color=0;
        ///Debemos ir avanzando la variable i para evitar el conteo repetido
        while(piedra[i]==color && i<=n) {
            i++;
            mismo_color++;
        }
        ///Añadimos al a respuesta las repetidas menos 1
        respuesta+=(mismo_color-1);
        ///Y listo, estamos en otra piedra de otro color listos para continuar
        ///o bien estamos en el final de las piedras y finalizamos
    }
    ///Retornamos la respuesta
    return respuesta;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ///Leemos n
    cin >> n;
    ///Leemos las n piedras y las guardamos en el arreglo, como son caracteres se leen seguidas
    for(int i=1; i<=n; i++) {
        cin >> piedra[i];
    }
    ///Imprimimos lo que de nuestra funcion calcula() en donde pondremos el resto del codigo
    cout << calcula();
    return 0;
}
