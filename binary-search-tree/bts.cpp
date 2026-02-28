#include<iostream>

template<typename T>
class BST {
private:
    struct Node {
        T valor;
        Node* esquerda;
        Node* direita;

        Node(T val): valor(val), esquerda(nullptr), direita(nullptr) {}
    };

    Node* raiz;

    void destroiRecursivo(Node* node) {
        if(node == nullptr) {
            return; //Não há mais nodes a serem destruídos
        }

        destroiRecursivo(node->esquerda); //Destrói subárvore da esquerda
        destroiRecursivo(node->direita); //Destrói subárvore da direita
        delete node;
    }

public:
    BST() : raiz(nullptr) {}
    
    ~BST() {

    };

    void insert(T valor) {
        raiz = insertRecursivo(raiz, valor);
    };

    bool search(T valor) {
        return searchRecursivo(raiz, valor);
    };
    
    void remove(T valor);
    
    void printOrder() {
        printOrderRecursivo(raiz); // Função recursiva visita todos os nós
        std::cout << std::endl;
    };

    void printOrderRecursivo(Node* node) {
        if(node == nullptr) {
            return; // Quando não há mais nó (nó vazio)
        }

        printOrderRecursivo(node->esquerda); // Vai pra esquerda
        std::cout << node->valor << " "; // Imprime o valor do nó atual
        printOrderRecursivo(node->direita); // Vai pra direita
    };

    Node* insertRecursivo(Node* node, T valor) {
        if(node == nullptr) {
            return new Node(valor); // chegou numa folha, cria aqui
        }

        if(valor < node->valor) {
            node->esquerda = insertRecursivo(node->esquerda, valor);
        } else {
            node->direita = insertRecursivo(node->direita, valor);
        }

        return node;
    };

    bool searchRecursivo(Node* node, T valor) {
        if(node == nullptr) {
            return false;
        }
        
        if(node->valor == valor) {
            return true;
        }

        if(valor < node->valor) {
            return searchRecursivo(node->esquerda, valor);
        } else {
            return searchRecursivo(node->direita, valor);
        }
    };
};

int main() {
    BST<int> bst;

    bst.insert(25);

    bst.insert(50);
    bst.insert(20);
    bst.insert(60);
    bst.insert(10);
    bst.insert(4);

    bst.printOrder();

    std::cout << "Procurando 10: " << bst.search(10) << std::endl;  // deve dar 1 (true)
    std::cout << "Procurando 99: " << bst.search(99) << std::endl;  // deve dar 0 (false)

    return 0;
}