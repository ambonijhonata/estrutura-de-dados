#include<stdio.h>
#include<stdlib.h>

#define MAX 10

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

int inserir(LISTA* lista, int elemento) {
	if (lista->qtdEelementos < MAX) {
		lista->array[lista->qtdEelementos].elemento = elemento;
		lista->qtdEelementos++;
		return 1;
	}

	return -1;
}

int inserirByIndex(LISTA* lista, int elemento, int index) {
	if (lista->qtdEelementos < MAX) {
		for (int i = lista->qtdEelementos - 1; i >= index; i--) {
			int atual = lista->array[i].elemento;
			lista->array[i + 1].elemento = atual;
		}
		lista->array[index].elemento = elemento;
		lista->qtdEelementos++;
	}
	else
	{
		return -1;
	}	
}

bool remove(LISTA* lista, int elemento) {
	int posicaoElemento = getElemento(lista, elemento);

	bool isRemoved = false;

	if (posicaoElemento >= 0) {
		for (int i = posicaoElemento; i < lista->qtdEelementos; i++) {
			lista->array[i].elemento = lista->array[i + 1].elemento;
			lista->qtdEelementos--;
		}
		isRemoved = true;
	}
	else {
		printf("Elemento nao encontrado na lista. Nada removido.\n");
	}

	return isRemoved;
}

void clear(LISTA* lista) {
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
	inserirByIndex(lista, 28, 3);

	printf("Elementos da lista: \n");
	printLista(lista);
	printf("Quantidade de elementos validos: %i.\n", qtdElementosValidos(lista));
	printf("Posicao do elemento 0 na lista: %i \n", getElemento(lista, 0));
	printf("Removendo item 0.\n");
	remove(lista, 0);
	printf("Elementos da lista: \n");
	printLista(lista);
	printf("Quantidade de elementos validos: %i.\n", qtdElementosValidos(lista));
	
	printf("Limpando a lista.\n");
	clear(lista);

	printf("Elementos da lista: \n");
	printLista(lista);
	printf("Quantidade de elementos validos: %i.\n", qtdElementosValidos(lista));

	return 0;
}