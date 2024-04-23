#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
	NO* ant;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void exibirReverso();
void inserirElemento();
void excluirPrimeiroElemento();
void excluirUltimoElemento();
void excluirElementoEspecifico();

//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 9) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Exibir quantidade de elementos \n";
		cout << "4 - Exibir elementos  \n";
		cout << "5 - Exibir elementos na ordem reversa \n";
		cout << "6 - Excluir primeiro elemento \n";
		cout << "7 - Excluir ultimo elemento \n";
		cout << "8 - Excluir elemento especifico \n";
		cout << "9 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:inserirElemento();
			break;
		case 3: exibirQuantidadeElementos();
			break;
		case 4: exibirElementos();
			break;
		case 5: exibirReverso();
			break;
		case 6: excluirPrimeiroElemento();
			break;
		case 7: excluirUltimoElemento();
			break;
		case 8: excluirElementoEspecifico();
			break;
		case 9:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista ja possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	novo->ant = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else {
		NO* aux = primeiro;
		NO* anterior = NULL;

		while (aux != NULL && aux->valor < novo->valor) {
			anterior = aux;
			aux = aux->prox;
		}

		if (anterior == NULL) {
			novo->prox = primeiro;
			primeiro->ant = novo;
			primeiro = novo;
		}
		else if (aux == NULL) {
			novo->ant = ultimo;
			ultimo->prox = novo;
			ultimo = novo;
		}
		else {
			novo->prox = aux;
			novo->ant = anterior;
			anterior->prox = novo;
			aux->ant = novo;
		}
	}
}


// funções a serem implementadas no exericio
void exibirReverso()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = ultimo;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->ant;
		}
	}
}

void excluirPrimeiroElemento()
{
	NO* aux = primeiro;
	if (aux == NULL) {
		cout << "Lista vazia \n";
		return;
	}

	if (aux->ant == NULL && aux->prox == NULL) {
		primeiro = NULL;
		ultimo = NULL;
		free(aux);
		cout << "Elemento excluido. \n";
		return;
	}

	primeiro = aux->prox;
	primeiro->ant = NULL;
	free(aux);
	cout << "Elemento excluido. \n";
}

void excluirUltimoElemento()
{
	NO* aux = ultimo;
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}

	if (aux->ant == NULL && aux->prox == NULL) {
		primeiro = NULL;
		ultimo = NULL;
		free(aux);
		cout << "Elemento excluido. \n";
		return;
	}

	ultimo = aux->ant;
	ultimo->prox = NULL;
	free(aux);
	cout << "Elemento excluido. \n";
}

void excluirElementoEspecifico() {

	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}

	int elementoExcluir;
	cout << "Digite o elemento a ser excluido: ";
	cin >> elementoExcluir;

	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == elementoExcluir) {
			if (aux->ant != NULL) {
				aux->ant->prox = aux->prox;
			}
			else {
				primeiro = aux->prox;
			}

			if (aux->prox != NULL) {
				aux->prox->ant = aux->ant;
			}
			else {
				ultimo = aux->ant;
			}

			free(aux);
			cout << "Elemento excluido \n";
			return;
		}

		aux = aux->prox;
	}

	cout << "Elemento nao encontrado \n";
}