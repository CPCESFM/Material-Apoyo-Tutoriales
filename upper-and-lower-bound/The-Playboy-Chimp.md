# Solución al problema de [The Playboy Chimp](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=661&page=show_problem&problem=1552)

Para empezar este problema declaramos un `arreglo` donde guardaremos nuestras chimpances.

```C++
int chimps[50000];
```
Luego leemos nuestro `n-tope` y las chimpances por medio de un ciclo `for()`.

```C++
  cin >> n;
	for(int i=0; i<n; i++) {
		cin >> chimps[i];
	}
```

Ya que tenemos esto pasamos a las preguntas que vienen con el cambio de altura de Luchu, por cada una de ellas buscaremos si es que están las dos chimpances que cumplen los requisitos de altura de Lucho. Para esto **notemos** que la función `upper_bound()` cumple la condición de la chimpance con la altura más próxima a él dentro del subconjuto de las más altas ya que encuentra el primer elemento estrictamente mayor al valor preguntado, si no mal recuerdas, esta función ocupa el `binary search` y justo podemos cumplir esto por la condición de que las chimpances están enfiladas de menor a mayor en cuento estaturas. 

```C++
  cin >> q;
	for(int j=0; j<q; j++) {
		cin >> Luchu;
		int *t_chimp=upper_bound(chimps, chimps+n, Luchu);
		int *s_chimp=t_chimp;
		s_chimp--;
		while(s_chimp>=chimps && *s_chimp==Luchu){
			s_chimp--;
		}
		if(s_chimp>=chimps) {
				cout << *s_chimp << " "; 
		}else {
				cout << "X ";
		}
		if(t_chimp==chimps+n) {
				cout << "X\n";
		}else {
				cout << *t_chimp << "\n";
		}
	}
}

```
Puedes ver en el código que una vez encontrado el ``apuntador`` al elemento  ``upper_bound()`` declaramos otro más que nos permite movernos en el arreglo, este debe hacerlo mientras no sea igual al primer elemnto de nuestro conjunto de chimpances o tenga guardada la estatura de Luchu. Así, con esta idea habremos terminado el problema. 



