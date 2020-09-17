#include <bits/stdc++.h>
using namespace std;
int k,n;
deque<int> dq;

void solucion(){
    //inicializamos el deque.
    int ini;//Esta variable solo es para leer los dulces.
    int alice=0,bob=0;//Cuantos turnos lleva cada uno(alice y bob).
    int turnos=1;//Cantidad de turnos.
    int comer;//Cuanto deben comer en cada turno.
    int va_a_comer;//Cuanto puede comer de dulce disponibles;

    cin >> n;
    for (int j=0; j<n; j++) {
        cin >> ini;
        dq.push_back(ini);
    }
    comer=dq.front();
    alice+=comer;
    dq.pop_front();

    if (!dq.empty()) {
        turnos++;
    }

    while(!dq.empty()){
        if(turnos%2){
            //Si la cantidad de turnos que llevan es par es el turno de bob y si es impar es el turno de alice.
            va_a_comer=dq.front();
            dq.pop_front();
            while (va_a_comer<=comer && !dq.empty()) {
                va_a_comer+=dq.front();
                dq.pop_front();
            }
            comer=va_a_comer;
            alice+=va_a_comer;
            turnos++;
        }else{
            va_a_comer=dq.back();
            dq.pop_back();
            while (va_a_comer<=comer && !dq.empty()) {
                va_a_comer+=dq.back();
                dq.pop_back();
            }
            comer=va_a_comer;
            bob+=va_a_comer;
            turnos++;

        }
    }
    if(turnos!=1){
        turnos--;
    }
    cout << turnos << " ";
    cout << alice << " ";
    cout << bob << "\n";

}

int main() {
    cin >> k;
    for (int i=1; i<=k; i++) {
        solucion();
    }
    return 0;
}

