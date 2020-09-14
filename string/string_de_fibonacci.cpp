#include <bits/stdc++.h>
using namespace std;
///Declaramos 3 strings para llevar la sucesión
string A,B,C;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ///Leemos los dos primeros string en A y B y leemos el termino n
    cin >> A >> B >> n;
    ///Primero probamos los casos mas simples, si nos piden n=1, n=2 u otro n
    if(n==1) {
        ///Primer termino de la sucesión
        cout << A;
    } else if(n==2) {
        ///Segundo termino de la sucesion
        cout << B;
    } else {
        ///Termino arbitrario de la sucesion
        ///Procedemos con un ciclo para generar a partir del tercer termino
        for(int i=3; i<=n; i++) {
            ///El operador + está sobrecargado para string, ¡concetena strings! (cuidado con el orden)
            ///La concatenación tiene O(m) con m la longitud del nuevo string
            ///Entonces C es la concatenación de los dos anteriores terminos
            C=A+B;
            ///Pasamos el valor del segundo termino como primero
            A=B;
            ///Y pasamos el valor del tercer termino (que acabamos de calcular) como segundo
            B=C;
            /**Hacemos este cambio de valores para la proxima vez que ingrese al for se re-calcule C
            es decir, el siguiente termino de la sucesión**/
        }
        ///Al final imprimimos C donde se guarda el i-esimo termino (al finalizar es el n-esimo)
        cout << C;
    }
    return 0;
}
