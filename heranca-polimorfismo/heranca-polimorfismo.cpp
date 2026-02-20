#include <iostream>
#include <cmath>

class Forma {
    public:
        virtual ~Forma() {} //Destrutor Virtual

        virtual double calcularArea() = 0;
        virtual double calcularPerimetro() = 0;

        virtual void imprime() {
            std::cout << "Área: " << calcularArea() << std::endl;
            std::cout << "Perimetro: " << calcularPerimetro() << std::endl;
        }
};

class Circulo : public Forma {
    private:
        double raio;

    public:
        Circulo (double r) : raio(r) {}

        double calcularArea()  override {
            return M_PI * (raio*raio);
        }

        double calcularPerimetro() override {
            return 2 * M_PI * raio;
        }

        void imprime() override {
            std::cout << "-----Calculando a área e perimetro do Circulo-----" << std::endl;
            std::cout << "Área: " << calcularArea() << std::endl;
            std::cout << "Perimetro: " << calcularPerimetro() << std::endl;
            std::cout << "\n";
        }
};

class Retangulo : public Forma {
    private:
        double base, altura;
    
    public:
        Retangulo(double b, double h) : base(b), altura(h) {}

        double calcularArea() override {
            return base * altura;
        }

        double calcularPerimetro() override {
            return 2 * (base + altura);
        }

        void imprime() override {
            std::cout << "-----Calculando a área e perimetro do Retangulo-----" << std::endl;
            std::cout << "Área: " << calcularArea() << std::endl;
            std::cout << "Perimetro: " << calcularPerimetro() << std::endl;
            std::cout << "\n";
        }
};

class Triangulo : public Forma {
    private:
        double lado1, lado2, lado3;

    public: 
        Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) { }

        double calcularArea() override {
            double s = (lado1 + lado2 + lado3) / 2.0; // Semi-perímetro
            return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));  // Heron
        }

        double calcularPerimetro() override {
            return lado1 + lado2 + lado3;
        }

        void imprime() override {
            std::cout << "-----Calculando a área e perimetro do Triangulo-----" << std::endl;
            std::cout << "Área: " << calcularArea() << std::endl;
            std::cout << "Perimetro: " << calcularPerimetro() << std::endl;
            std::cout << "\n";
        }
};

int main() {

    //Código inicial
    /*
        Forma* formaCirculo = new Circulo(10);
        formaCirculo->imprime();
    
        Forma* formaRetangulo = new Retangulo(10, 5);
        formaRetangulo->imprime();

        Forma* formaTriangulo = new Triangulo(10, 10, 11);
        formaTriangulo->imprime();

        delete formaCirculo;
        delete formaRetangulo;
        delete formaTriangulo;

    */

    //Versão Otimizada
    int qtdFormas = 3;
    Forma* formas[qtdFormas];
    
    formas[0] = new Circulo(10);
    formas[1] = new Retangulo(10, 5);
    formas[2] = new Triangulo(10, 10, 11);

    for(int i=0; i < qtdFormas; i++) {
        formas[i]->imprime();
    }

    for(int i=0; i < qtdFormas; i++){
        delete formas[i];
    }
    
    return 0;
}