#include <iostream>
#include <thread>
#include <mutex>

int contador = 0; //variável compartilhada entre threads
std::mutex mtx;

void incrementa() {
    for(int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock(mtx);
        contador++;
        // Unlock Automático
    }
}

void imprime_mensagens(int id) {
    for(int i = 0; i < 5; i++){
        //std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Thread " << id << " - mensagem " << i << std::endl;
    }
    
}

int main() {
    std::thread t1(imprime_mensagens, 1);
    std::thread t2(imprime_mensagens, 2);
    std::thread t3(imprime_mensagens, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

