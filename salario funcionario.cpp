#include <iostream>
#include <string>
using namespace std;

struct Funcionario {
    string nome;
    float salario;
    Funcionario* proximo;
};

class ListaFuncionarios {
private:
    Funcionario* inicio;

public:
    ListaFuncionarios() {
        inicio = NULL;
    }

    void inserir(string nome, float salario) {
        Funcionario* novoFuncionario = new Funcionario;
        novoFuncionario->nome = nome;
        novoFuncionario->salario = salario;
        novoFuncionario->proximo = NULL;

        if (inicio == NULL) {
            inicio = novoFuncionario;
        }
        else {
            Funcionario* atual = inicio;
            Funcionario* anterior = NULL;

            while (atual != NULL && atual->salario >= salario) {
                anterior = atual;
                atual = atual->proximo;
            }

            if (anterior == NULL) {
                novoFuncionario->proximo = inicio;
                inicio = novoFuncionario;
            }
            else {
                anterior->proximo = novoFuncionario;
                novoFuncionario->proximo = atual;
            }
        }
    }

    void mostrarMaiorSalario() {
        if (inicio == NULL) {
            cout << "Nenhum funcionario cadastrado.\n";
            return;
        }

        float maiorSalario = inicio->salario;
        Funcionario* atual = inicio;

        while (atual != NULL && atual->salario == maiorSalario) {
            cout << "Nome: " << atual->nome << ", Salario: " << atual->salario << endl;
            atual = atual->proximo;
        }
    }

    float calcularMediaSalarial() {
        if (inicio == NULL) {
            return 0.0;
        }

        float somaSalarios = 0.0;
        int contador = 0;
        Funcionario* atual = inicio;

        while (atual != NULL) {
            somaSalarios += atual->salario;
            contador++;
            atual = atual->proximo;
        }

        return somaSalarios / contador;
    }

    int contarSalariosSuperiores(float salario) {
        int quantidade = 0;
        Funcionario* atual = inicio;

        while (atual != NULL) {
            if (atual->salario > salario) {
                quantidade++;
            }
            atual = atual->proximo;
        }

        return quantidade;
    }
};

int main() {
    ListaFuncionarios lista;

    for (int i = 0; i < 8; i++) {
        string nome;
        float salario;

        cout << "Digite o nome do funcionario " << i+1 << ": ";
        cin >> nome;
        cout << "Digite o salario do funcionario " << i+1 << ": ";
        cin >> salario;

        lista.inserir(nome, salario);
    }

    cout << "\n--- Resultados ---\n";

    cout << "Funcionario(s) com maior salario:\n";
    lista.mostrarMaiorSalario();

    float mediaSalarial = lista.calcularMediaSalarial();
    cout << "Media salarial de todos os funcionarios: " << mediaSalarial << endl;

    float salarioUsuario;
    cout << "Digite um salario para verificar a quantidade de funcionarios com salario superior: ";
    cin >> salarioUsuario;

    int quantidadeSalariosSuperiores = lista.contarSalariosSuperiores(salarioUsuario);
    if (quantidadeSalariosSuperiores > 0) {
        cout << "Quantidade de funcionarios com salario superior a " << salarioUsuario << ": " << quantidadeSalariosSuperiores << endl;
    } else {
        cout << "Nenhum funcionario atinge a criterio.\n";
    }

    return 0;
}
