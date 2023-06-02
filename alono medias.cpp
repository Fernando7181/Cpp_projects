#include <iostream>
#include <string>
using namespace std;

class Aluno {
public:
    string nome;
    float nota;
    Aluno* proximo;
    Aluno* anterior;

    Aluno(string nome, float nota) {
        this->nome = nome;
        this->nota = nota;
        this->proximo = nullptr;
        this->anterior = nullptr;
    }
};

Aluno* cadastrar_aluno() {
    string nome;
    float nota;

    cout << "Digite o nome do aluno: ";
    getline(cin, nome);
    cout << "Digite a nota final do aluno: ";
    cin >> nota;
    cin.ignore(); 

    return new Aluno(nome, nota);
}

void mostrar_aprovados(Aluno* aluno) {
    cout << "Alunos aprovados:\n";
    while (aluno != nullptr) {
        if (aluno->nota >= 7) {
            cout << aluno->nome << endl;
        }
        aluno = aluno->proximo;
    }
}

int main() {
    Aluno* primeiro_aluno = nullptr;
    Aluno* ultimo_aluno = nullptr;

  
    for (int i = 0; i < 5; i++) {
        cout << "\nCadastro do Aluno " << i + 1 << endl;
        Aluno* novo_aluno = cadastrar_aluno();

        if (primeiro_aluno == nullptr) {
           
            primeiro_aluno = novo_aluno;
            ultimo_aluno = novo_aluno;
        } else {
            
            novo_aluno->anterior = ultimo_aluno;
            ultimo_aluno->proximo = novo_aluno;
            ultimo_aluno = novo_aluno;
        }
    }

   
    mostrar_aprovados(primeiro_aluno);

    return 0;
}
