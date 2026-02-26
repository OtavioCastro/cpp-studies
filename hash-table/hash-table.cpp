#include <iostream>

template <typename K, typename V>
class HashTable {
private:
    struct Node {
        K chave;
        V valor;
        Node* proximo;
    };

    Node** tabela; // array de ponteiros para Node
    int capacidade;

    int hash(K chave) {
        int soma = 0;
        for(char c : chave) {
            soma += c; // soma o valor ASCII de cada caractere
        }
        return soma % capacidade;
    }

public: 
    HashTable(int cap) {
        capacidade = cap;  // guarda a capacidade
        tabela = new Node*[cap];  // aloca o array
    
        // inicializa todas as posições com nullptr
        for(int i = 0; i < capacidade; i++) {
            tabela[i] = nullptr;
        }
    };

    ~HashTable() {
        delete[] tabela;
    };

    void insert(K chave, V valor) {
        Node* nodeToAdd = new Node();  // cria o Node corretamente
        nodeToAdd->chave = chave;
        nodeToAdd->valor = valor;
        nodeToAdd->proximo = nullptr;  // importante!

        int indice = hash(chave);

        if(tabela[indice] == nullptr) {
            tabela[indice] = nodeToAdd;
        } else {
            Node* atual = tabela[indice];
            while(atual->proximo != nullptr) {  // para no penúltimo
                atual = atual->proximo;
            }
            atual->proximo = nodeToAdd;  // cola no final
        }
    }

    V get(K chave) {
        int indice = hash(chave); //Índice onde é guardado o node
        Node* atual = tabela[indice];

        while(atual != nullptr) {
            if(atual->chave == chave) {
                return atual->valor;
            }
            atual = atual->proximo;
        }

        return V();
    };

    void remove(K chave) {
        int indice = hash(chave);
        Node* atual = tabela[indice];

        if(atual != nullptr && atual->chave == chave) {
            tabela[indice] = atual -> proximo;
            delete atual;
            return;
        }

        while(atual != nullptr && atual->proximo != nullptr) {
            if(atual->proximo->chave == chave) {
                Node* nodeToRemove = atual->proximo;
                atual->proximo = nodeToRemove->proximo;
                delete nodeToRemove;
                return;
            }
            atual = atual->proximo;
        }
    };

    bool contains(K chave) {
        int indice = hash(chave);
        Node* atual = tabela[indice];

        while(atual != nullptr) {
            if(atual->chave == chave){
                return true;
            }
            atual = atual->proximo;
        }

        // Assumindo que nunca entrou na condição atual->chave == chave
        // Devemos retornar false pois entendemos que não existe a chave na tabela
        return false;
    };

};

int main() {
    HashTable<std::string, int> hashTable(5);

    std::cout << "Adicionando alface... Valor R$5" <<std::endl;
    hashTable.insert("alface", 5);

    std::cout << "Adicionando alface... Valor R$3" <<std::endl;
    hashTable.insert("batata", 3);

    std::cout << "Adicionando alface... Valor R$2" <<std::endl;
    hashTable.insert("cebola", 2);

    std::cout << "Tem ALFACE: " << hashTable.contains("alface") << std::endl;
    std::cout << "Tem BATATA: " << hashTable.contains("batata") << std::endl;
    std::cout << "Tem CENOURA: " << hashTable.contains("cenoura") << std::endl;
    std::cout << "Tem CEBOLA: " << hashTable.contains("cebola") << std::endl;

    std::cout << "Valor Alface: R$" << hashTable.get("alface") << std::endl;
    std::cout << "Valor Batata: R$" << hashTable.get("batata") << std::endl;
    std::cout << "Valor Cebola: R$" << hashTable.get("cebola") << std::endl;

    std::cout << "Puxa vida, acabou a batata..." << std::endl;
    hashTable.remove("batata");

    std::cout << "Confirmando que a batata foi removida... Tem batata: " << hashTable.contains("batata") << std::endl;


    return 0;
}