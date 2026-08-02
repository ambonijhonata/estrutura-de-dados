#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct {
	int elemento;
} REGISTRO;

typedef struct {
	REGISTRO array[MAX];
	int qtdEelementos;
} LISTA;

LISTA* criarLista() {
	LISTA *lista = (LISTA*) malloc(sizeof(LISTA));

	//esse if existe pois o malloc pode não conseguir alocar memória e retornar null
	if (lista == NULL) {
		return NULL;
	}

	//é obrigatório pois o malloc pode alocar um espaço de memória já usado anteriormente que continha lixo. O int não inicia com zero por padrão no malloc.
	lista->qtdEelementos = 0;

	return lista;
}

//o const no parametro indica que a função não deve alterar a lista, visto que ela só irá consultar o total de itens;
int qtdElementosValidos(const LISTA *lista) {
	return lista->qtdEelementos;
}

int main() {

	LISTA* lista = criarLista();

	if (lista == NULL) {
		printf("Nao foi possivel criar a lista.");
		return 1;
	}

	printf("Quantidade de elementos validos: %i.", qtdElementosValidos(lista));

	return 0;
}