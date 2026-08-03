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

void printLista(const LISTA* lista) {
	for (int i = 0; i < lista->qtdEelementos; i++) {
		printf("%i\n", lista->array[i].elemento);
	}
}

int getElemento(const LISTA* lista, int elemento) {
	for (int i = 0; i < lista->qtdEelementos; i++) {
		if (lista->array[i].elemento == elemento) {
			return i;
		}
	}

	return -1;
}

void inserir(LISTA* lista, int elemento) {
	lista->array[lista->qtdEelementos].elemento = elemento;
	lista->qtdEelementos++;
}

int main() {

	LISTA* lista = criarLista();

	if (lista == NULL) {
		printf("Nao foi possivel criar a lista.");
		return 1;
	}		

	printf("inserindo elementos na lista \n");
	inserir(lista, 2);
	inserir(lista, 0);
	inserir(lista, 1);

	printf("Elementos da lista: \n");
	printLista(lista);
	printf("Quantidade de elementos validos: %i.\n", qtdElementosValidos(lista));
	printf("Posicao do elemento 0 na lista: %i \n", getElemento(lista, 0));

	return 0;
}