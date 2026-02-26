#include <iostream>

class Pessoa {
private:
    std::string nome;
    int idade;

public:
    Pessoa(std::string n, int i) : nome(n), idade(i) {
        std::cout << "Construindo " << nome << std::endl;
    }
    
    ~Pessoa() {
        std::cout << "Destruindo " << nome << std::endl;
    }
    
    void apresenta() {
        std::cout << "Oi, sou " << nome << ", tenho " << idade << " anos" << std::endl;
    }
};

int main() {
    std::cout << "=== EXEMPLO 1: Stack ===" << std::endl;
    {
        Pessoa joao("João", 25);  // cria na stack, SEM new
        joao.apresenta();         // usa . (ponto)
    }  // joao é destruído AUTOMATICAMENTE aqui
    
    std::cout << "\n=== EXEMPLO 2: Heap ===" << std::endl;
    {
        Pessoa* maria = new Pessoa("Maria", 30);  // cria na heap, COM new
        maria->apresenta();                       // usa -> (seta)
        delete maria;                             // TEM que deletar manualmente
    }
    
    std::cout << "\n=== EXEMPLO 3: Comparação ===" << std::endl;
    
    // Stack
    Pessoa pedro("Pedro", 20);
    std::cout << "Endereço de pedro: " << &pedro << std::endl;
    
    // Heap
    Pessoa* ana = new Pessoa("Ana", 22);
    std::cout << "Endereço guardado em ana: " << ana << std::endl;
    std::cout << "Endereço da VARIÁVEL ana: " << &ana << std::endl;
    
    delete ana;
    
    return 0;
}  // pedro é destruído automaticamente aqui