///¿Habrá una forma de hacer esto más rápido? Interesante ...

long long int A_elevado_a_la_B(int A, int B) {
	long long int res=1;
	for(int i=1; i<=B; i++) {
		res*=A;
	}
	return res;
}
