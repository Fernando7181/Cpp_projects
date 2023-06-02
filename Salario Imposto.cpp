#include <iostream>
#include <string>
using namespace std;

class Funcionario {
public:
    string nome;
    float salario;
    Funcionario* proximo;
    Funcionario* anterior;

    Funcionario(string nome, float salario) {
        this->nome = nome;
        this->salario = salario;
        this->proximo = nullptr;
        this->anterior = nullptr;
    }
};

Funcionario* cadastrar_funcionario() {
    string nome;
    float salario;

    cout << "Digite o nome do funcionário: ";
    getline(cin, nome);
    cout << "Digite o salário do funcionário: ";
    cin >> salario;
    cin.ignore(); 

    return new Funcionario(nome, salario);
}

float calcular_imposto(float salario) {
    if (salario <= 2000) {
        return 0;
    } else if (salario <= 3000) {
        return salario * 0.1;
    } else if (salario <= 4000) {
        return salario * 0.15;
    } else {
        return salario * 0.2;
    }
}

void mostrar_funcionarios(Funcionario* funcionario) {
    cout << "Nome\t\tImposto\t\tValor a Receber\n";
    while (funcionario != nullptr) {
        float imposto = calcular_imposto(funcionario->salario);
        float valor_receber = funcionario->salario - imposto;
        cout << funcionario->nome << "\t\t" << imposto << "\t\t" << valor_receber << "\n";
        funcionario = funcionario->proximo;
    }
}

int main() {
    Funcionario* primeiro_funcionario = nullptr;
    Funcionario* ultimo_funcionario = nullptr;

    for (int i = 0; i < 6; i++) {
        cout << "\nCadastro de Funcionário\n";
        Funcionario* novo_funcionario = cadastrar_funcionario();

        if (primeiro_funcionario == nullptr) {
            primeiro_funcionario = novo_funcionario;
            ultimo_funcionario = novo_funcionario;
        } else {
            bool inserido = false;
            Funcionario* atual = primeiro_funcionario;
            while (atual != nullptr) {
                if (novo_funcionario->salario < atual->salario) {
                    novo_funcionario->proximo = atual;
                    novo_funcionario->anterior = atual->anterior;
                    if (atual->anterior != nullptr) {
                        atual->anterior->proximo = novo_funcionario;
                    } else {
                        primeiro_funcionario = novo_funcionario;
                    }
                    atual->anterior = novo_funcionario;
                    inserido = true;
                    break;
                }
                atual = atual->proximo;
            }
            if (!inserido) {
                ultimo_funcionario->proximo = novo_funcionario;
                novo_funcionario->anterior = ultimo_funcionario;
                ultimo_funcionario = novo_funcionario;
            }
        }
    }

    mostrar_funcionarios(primeiro_funcionario);

    return 0;
}
