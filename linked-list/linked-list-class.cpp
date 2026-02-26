#include <iostream>

class LinkedList {
private:
    struct Node {
        int valor;
        Node* proximo;
    };
    Node* cabeca;

public:
    LinkedList() {
        cabeca = nullptr;
    }

    ~LinkedList() { // destrutor 
        std::cout << "----- Destruindo o node -----" << std::endl;
        while(cabeca != nullptr){
            Node* nodeParaRemover = cabeca;
            cabeca = cabeca->proximo;    
            delete nodeParaRemover;
        }
    }          

    void adiciona(int valor) {
        Node* novoNode = new Node();
        novoNode->valor = valor;
        novoNode->proximo = nullptr;

        if(cabeca == nullptr) { // lista vazia
            cabeca = novoNode;
            return;
        }

        Node* ultimoNode = getUltimoNode(cabeca);
        ultimoNode->proximo = novoNode;
    }

    void remove(int valor) {

        if(cabeca != nullptr && cabeca -> valor == valor) {
            Node* nodeParaRemover = cabeca;
            cabeca = cabeca->proximo;
            delete nodeParaRemover;
            return;
        }

        Node* atual = cabeca;
        
        // Percorre o node
        while(atual != nullptr && atual->proximo != nullptr) {
            if(atual->proximo->valor == valor) {
                Node* nodeParaRemover = atual->proximo;
                atual->proximo = nodeParaRemover->proximo;
                delete nodeParaRemover;
                return;
            }
            atual = atual->proximo;
        }
    }

    void imprime() {

        std::cout << "----- Imprimindo o node -----" << std::endl;
        //Apenas visual, uma barra indicando o inicio do node
        std::cout << "| ";

        Node* atual = cabeca;

        while(atual != nullptr) {
            std::cout << atual->valor << " | ";
            atual = atual->proximo;
        }

        std::cout << std::endl;
    }

    Node* getUltimoNode(Node* nodeAtual) {
    // percorre até o último node
        Node* atual = cabeca;
        while(atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        return atual;
    }
};


int main() {
    LinkedList lista;

    lista.adiciona(10);
    lista.adiciona(20);
    lista.adiciona(30);
    lista.imprime();

    lista.remove(20);
    lista.imprime();

    return 0;
}