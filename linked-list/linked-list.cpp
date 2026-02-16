#include <iostream>
#include <memory>

struct Node {
    int valor;
    Node* proximo;
};

Node* getUltimoNode(Node* nodeAtual);

void adiciona(Node* nodeAtual, Node* nodeParaAdd) {
    std::cout << "Adicionando o node de valor " << nodeParaAdd->valor << std::endl;
    Node* ultimoNode = getUltimoNode(nodeAtual);
    ultimoNode->proximo = nodeParaAdd;
}

void imprime(Node* node) {
    std::cout << "----- Imprimindo a lista -----" << std::endl;

    while(node != nullptr) { // verifica o node em si, não o proximo
        std::cout << node->valor << " | ";
        node = node->proximo;
    }

    std::cout << std::endl;
}

void removeNode(Node** cabeca, Node* nodeParaRemover) {
    std::cout << "Removendo node de valor: " << nodeParaRemover->valor << std::endl;

    // caso especial: remover a cabeça da lista
    if(*cabeca == nodeParaRemover) {
        *cabeca = nodeParaRemover->proximo;
        delete nodeParaRemover;
        return;
    }

    // percorre até achar o node ANTERIOR ao que vai ser removido
    Node* nodeAtual = *cabeca;
    while(nodeAtual != nullptr && nodeAtual->proximo != nodeParaRemover) {
        nodeAtual = nodeAtual->proximo;
    }

    if(nodeAtual != nullptr) {
        nodeAtual->proximo = nodeParaRemover->proximo;
        delete nodeParaRemover;
    }
}

Node* getUltimoNode(Node* nodeAtual) {
    while(nodeAtual->proximo != nullptr) {
        nodeAtual = nodeAtual->proximo;
    }
    return nodeAtual;
}

int main() {
    // inicializa SEMPRE o proximo com nullptr
    Node* nodePrincipal = new Node();
    nodePrincipal->valor = 20;
    nodePrincipal->proximo = nullptr;

    Node* node2 = new Node();
    node2->valor = 30;
    node2->proximo = nullptr;

    Node* node3 = new Node();
    node3->valor = 40;
    node3->proximo = nullptr;

    std::cout << "----- LISTA INICIAL -----" << std::endl;
    imprime(nodePrincipal);

    adiciona(nodePrincipal, node2);
    adiciona(nodePrincipal, node3);

    std::cout << "\n----- DEPOIS DE ADICIONAR -----" << std::endl;
    imprime(nodePrincipal);

    std::cout << "\n----- DEPOIS DE REMOVER O NODE 2 -----" << std::endl;
    removeNode(&nodePrincipal, node2);
    imprime(nodePrincipal);

    // libera memória
    delete node3;
    delete nodePrincipal;

    return 0;
}