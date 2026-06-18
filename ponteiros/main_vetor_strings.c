#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * aloca_str( char *msg );
void mostra_vetor( char **v, int n );
void desaloca_vetor( char **v, int n );
void insere_string( char ***v, int *p_n, char *s );

int main(int argc, char *argv[]) {
	char **vetor = NULL;
	int n = 0;
	char *str = aloca_str( "Digite um texto (ou 'sair' para sair): " );
	
	while( strcmp(str, "sair") != 0 ){
		insere_string( &vetor, &n, str );
		str = aloca_str( "Digite um texto (ou 'sair' para sair): " );
	}
	free( str );	

	mostra_vetor( vetor, n );

	desaloca_vetor( vetor, n );
	
	return 0;
}

char * aloca_str( char *msg ){
	char buffer[1001];
	printf("%s", msg);
	scanf(" %[^\n]", buffer);
	char *p = malloc( sizeof(char) * (strlen(buffer) + 1) );
	strcpy( p, buffer );
	return p;
}

void mostra_vetor( char **v, int n ){
	int i;
	printf("Lista de strings:\n");
	for( i = 0 ; i < n ; i++ )
		printf("[%d] : '%s'\n", i , v[i] );
}

void desaloca_vetor( char **v, int n ){
	int i;
	for( i = 0 ; i < n ; i++ )
		free( v[i] );
	free( v );
}

void insere_string( char ***v, int *p_n, char *s ){
	(*p_n)++;
	*v = realloc( *v, sizeof(char*) * *p_n );
	(*v)[*p_n-1] = s;
}



