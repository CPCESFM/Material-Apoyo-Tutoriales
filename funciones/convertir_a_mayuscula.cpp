/*Esta función recibe una letra minúscula (hace la
comprobación) y devuelve esa misma letra mayúscula*/

char a_Mayuscula(char letra) {
 	if('A'<=letra && letra<='Z') {
    	return letra;
 	}
	char mayuscula=letra-'a';
	mayuscula+='A';
	return mayuscula;
}
