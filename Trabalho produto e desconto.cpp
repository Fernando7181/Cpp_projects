#include <iostream>
using namespace std;

// Definição da estrutura do nó da lista
struct Produto {
    int codigo;
    float preco;
    int quantidade;
    Produto* proximo;
};

// Função para adicionar um novo produto à lista
void adicionarProduto(Produto*& lista, int codigo, float preco, int quantidade) {
    Produto* novoProduto = new Produto;
    novoProduto->codigo = codigo;
    novoProduto->preco = preco;
    novoProduto->quantidade = quantidade;
    novoProduto->proximo = lista;
    lista = novoProduto;
}

// Função para aplicar desconto a todos os produtos da lista
void aplicarDesconto(Produto* lista, float desconto) {
    Produto* atual = lista;
    while (atual != NULL) {
        atual->preco -= atual->preco * (desconto / 100);
        atual = atual->proximo;
    }
}

// Função para imprimir a lista de produtos
void imprimirLista(Produto* lista) {
    Produto* atual = lista;
    while (atual != NULL) {
        cout << "Código: " << atual->codigo << endl;
        cout << "Preço: R$" << atual->preco << endl;
        cout << "Quantidade: " << atual->quantidade << endl;
        cout << endl;
        atual = atual->proximo;
    }
}

int main() {
    Produto* lista = NULL;

    // Cadastro dos produtos
    for (int i = 0; i < 5; i++) {
        int codigo, quantidade;
        float preco;
        cout << "Cadastro do produto " << i+1 << endl;
        cout << "Código: ";
        cin >> codigo;
        cout << "Preço: R$";
        cin >> preco;
        cout << "Quantidade: ";
        cin >> quantidade;
        cout << endl;

        adicionarProduto(lista, codigo, preco, quantidade);
    }

    // Aplicação do desconto
    float desconto;
    cout << "Digite a taxa de desconto a ser aplicada (%): ";
    cin >> desconto;
    aplicarDesconto(lista, desconto);

    // Impressão da lista de produtos com os preços atualizados
    cout << endl << "Lista de produtos com desconto:" << endl;
    imprimirLista(lista);

    // Liberação da memória alocada pela lista
    Produto* atual = lista;
    while (atual != NULL) {
        Produto* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    return 0;
}
