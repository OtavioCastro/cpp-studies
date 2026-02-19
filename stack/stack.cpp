#include <iostream>

template <typename T>
class Stack {
private:
    T* elementos;
    int capacidade;
    int topo;

    void redimensiona() {
        T* novosElementos =new T[capacidade*2];

        for(int i=0; i<= topo; i++){
            novosElementos[i] = elementos[i];
        }

        delete[] elementos;

        elementos = novosElementos;
        capacidade = capacidade * 2;
    }

public:
    Stack() {
        capacidade = 10;
        topo = -1;
        elementos = new T[capacidade];
    }

    ~Stack() {
        delete[] elementos;
    }

    void push(T valor) {
        if((topo + 1) >= capacidade) {
            std::cout << "Array será redimensionado..." << std::endl;
            redimensiona(); // funcao pra criar uma nova Stack com mais espaços
        }

        topo++;
        elementos[topo] = valor;
    }

    T pop(){
        T elementoToRemove = elementos[topo];
        topo--;
        return elementoToRemove;
    };

    T peek(){
        return elementos[topo];
    };

    bool isEmpty() {
        return topo == -1;
    }    
};

int main() {

    Stack<int> stackNumeros;
    Stack<std::string> stackNomes;

    std::cout << "----- STACK DE NUMEROS -----" << std::endl;

    stackNumeros.push(10);
    stackNumeros.push(2);
    stackNumeros.push(50);
    stackNumeros.push(31);
    stackNumeros.push(22);
    stackNumeros.push(37);
    stackNumeros.push(88);
    stackNumeros.push(21);
    stackNumeros.push(43);
    stackNumeros.push(98);
    stackNumeros.push(128);
    stackNumeros.push(94);
    stackNumeros.push(77);
    stackNumeros.push(61);
    stackNumeros.push(28);
    stackNumeros.push(37);

    if(!stackNumeros.isEmpty()) {
        std::cout << "Topo da pilha de números: " << stackNumeros.peek() << std::endl;
        std::cout << "Número removido: " << stackNumeros.pop() << " da pilha. Topo." << std::endl;
    }

    while(!stackNumeros.isEmpty()) {
        std::cout << "Removendo o número: " << stackNumeros.pop() << std::endl;
    }

    std::cout << "\n\n";

    std::cout << "----- STACK DE NOMES -----" << std::endl;

    stackNomes.push("João");
    stackNomes.push("Maria");
    stackNomes.push("Tavinho");
    stackNomes.push("Claude");

    if(!stackNomes.isEmpty()) {
        std::cout << "Topo da pilha: " << stackNomes.peek() << std::endl;
        std::cout << "Nome removido: " << stackNomes.pop() << " da pilha. Topo." << std::endl;
    }
    
    while(!stackNomes.isEmpty()) {
        std::cout << "Removendo o nome: " << stackNomes.pop() << std::endl;
    }    

    return 0;
}