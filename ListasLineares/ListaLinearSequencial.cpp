#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct {
	int elemento;
	bool isPreenchido;
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

	for (int i = 0; i < MAX; i++) {
		lista->array[i].isPreenchido = false;
	}

	return lista;
}

//o const no parametro indica que a função não deve alterar a lista, visto que ela só irá consultar o total de itens;
int qtdElementosValidos(const LISTA *lista) {
	return lista->qtdEelementos;
}

void printLista(const LISTA* lista) {
	for (int i = 0; i < MAX; i++) {
		if (lista->array[i].isPreenchido) {
			printf("%i\n", lista->array[i].elemento);
		}
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

int inserir(LISTA* lista, int elemento) {
	if (lista->qtdEelementos < MAX) {
		lista->array[lista->qtdEelementos].elemento = elemento;
		lista->array[lista->qtdEelementos].isPreenchido = true;

		lista->qtdEelementos++;
		return 1;
	}

	return -1;
}

void inserirByIndex(LISTA* lista, int elemento, int index) {	

	lista->array[index].elemento = elemento;
	lista->array[index].isPreenchido = true;

	if (lista->qtdEelementos < MAX) {
		lista->qtdEelementos++;
	}	
}

bool remove(LISTA* lista, int elemento) {
	int posicaoElemento = getElemento(lista, elemento);

	if(posicaoElemento != -1) {
		lista->array[posicaoElemento].isPreenchido = false;
		lista->qtdEelementos--;
		return true;
	}
	return false;
}

void clear(LISTA* lista) {
	for (int i = 0; i < 10; i++) {
		lista->array[i].isPreenchido = false;
	}
	lista->qtdEelementos = 0;
}

int main() {

	LISTA* lista = criarLista();

	if (lista == NULL) {
		printf("Nao foi possivel criar a lista.");
		return 1;
	}		

	printf("inserindo elementos na lista \n");
	inserir(lista, 8);
	inserir(lista, 2);
	inserir(lista, 15);
	inserir(lista, 32);
	inserir(lista, 4);
	inserir(lista, 48);		
	inserirByIndex(lista, 38, 8);
	printLista(lista);
	inserirByIndex(lista, 39, 7);
	inserirByIndex(lista, 63, 9);
	inserirByIndex(lista, 21, 6);
	inserirByIndex(lista, 37, 8);
	//inserirByIndex(lista, 28, 3);

	printf("Elementos da lista: \n");
	printLista(lista);
	printf("Quantidade de elementos validos: %i.\n", qtdElementosValidos(lista));
	printf("Posicao do elemento 0 na lista: %i \n", getElemento(lista,37));
	printf("Removendo item 37: %s.\n", remove(lista, 37) ? "true" : "false");
	
	printf("Elementos da lista: \n");
	printLista(lista);
	printf("Quantidade de elementos validos: %i.\n", qtdElementosValidos(lista));
	
	printf("Limpando a lista.\n");
	clear(lista);
	inserir(lista, 2);
	inserirByIndex(lista, 31, 8);
	printf("Elementos da lista: \n");
	printLista(lista);
	printf("Quantidade de elementos validos: %i.\n", qtdElementosValidos(lista));

	return 0;
}
