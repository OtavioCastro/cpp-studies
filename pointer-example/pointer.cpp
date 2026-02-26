#include <iostream>
#include <memory>

void dobra(int* p) {
    *p = *p * 2;
}

int main() {
    int x = 10;
    
    std::unique_ptr<int> valorUnique = std::make_unique<int>(25);

    dobra(&x);
    dobra(valorUnique.get());

    std::cout << "Valor x: " << x << std::endl;
    std::cout << "Valor unique: " << *valorUnique << std::endl;

    return 0;
}