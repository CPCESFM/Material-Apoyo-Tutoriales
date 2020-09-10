#include <bits/stdc++.h>

using namespace std;

int n,m,p,aux;

int prioridad[10];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n ;



    while (n!=0){

        queue < pair <int,int> > imprime;

        memset( prioridad , 0 , sizeof prioridad );

        cin >> m >> p ;

        for (int i=0 ;i < m ; i++){

            cin >> aux;

            prioridad[aux]++;

            imprime.push(make_pair(aux,i));

        }
        int minutos=0;

        bool seimp = false ;

        while (seimp!=true){

            bool masimport = true ;

            pair <int , int > act = imprime.front();

            for (int i = act.first + 1 ; i < 10 ; i++){
                if (prioridad[i] > 0){

                    masimport = false ;

                    break;

                }
            }

            if (masimport!=false){

                minutos++;

                if (act.second == p){
                    seimp = true ;
                    cout << minutos << "\n";
                    break;
                }
                prioridad[act.first]--;
            }

            else imprime.push(act);

            imprime.pop();

        }
        n--;
    }


    return 0;
}
