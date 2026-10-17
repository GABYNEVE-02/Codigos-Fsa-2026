
#include <iostream>
#include <stdexcept>
using namespace std;

// Codigo do gpt 

class ArrayQueue {
private:
    int* dados;       // Array que armazena os elementos da fila
    int capacidade;   // Quantidade máxima de elementos
    int inicio;       // Posição do primeiro elemento
    int fim;          // Próxima posição onde será inserido um elemento
    int tamanho;      // Quantidade atual de elementos

public:
    // Construtor: prepara a fila com uma capacidade definida
    ArrayQueue(int cap) {
        if (cap <= 0) {
            throw invalid_argument("Capacidade invalida!");
        }

        capacidade = cap;
        dados = new int[capacidade];

        inicio = 0;   // A fila começa na posição zero
        fim = 0;      // A primeira inserção será na posição zero
        tamanho = 0;  // A fila começa vazia
    }

    // Destrutor: libera a memória alocada pelo array
    ~ArrayQueue() {
        delete[] dados;
    }

    // Verifica se a fila está vazia
    bool isEmpty() {
        return tamanho == 0;
    }

    // Verifica se a fila está cheia
    bool isFull() {
        return tamanho == capacidade;
    }

    // Insere um elemento no final da fila
    void enqueue(int valor) {
        // Não podemos inserir se todas as posições estiverem ocupadas
        if (isFull()) {
            throw overflow_error("Fila cheia!");
        }

        // Guarda o valor na posição indicada por fim
        dados[fim] = valor;

        // Avança para a próxima posição.
        // O operador % faz a posição voltar a zero
        // quando chegamos ao final do array.
        fim = (fim + 1) % capacidade;

        // Atualiza a quantidade de elementos
        tamanho++;
    }

    // Remove e retorna o primeiro elemento da fila
    int dequeue() {
        // Não podemos remover um elemento de uma fila vazia
        if (isEmpty()) {
            throw underflow_error("Fila vazia!");
        }

        // Guarda o primeiro elemento para retorná-lo
        int valor = dados[inicio];

        // Avança o início para o próximo elemento
        // O módulo permite circular pelo array
        inicio = (inicio + 1) % capacidade;

        // Agora existe um elemento a menos na fila
        tamanho--;

        return valor;
    }

    // Consulta o primeiro elemento sem removê-lo
    int front() {
        if (isEmpty()) {
            throw underflow_error("Fila vazia!");
        }

        return dados[inicio];
    }

    // Retorna a quantidade atual de elementos
    int size() {
        return tamanho;
    }

    // Mostra os elementos na ordem em que serão removidos
    void mostrar() {
        cout << "Fila: ";

        for (int i = 0; i < tamanho; i++) {
            // Calcula a posição real de cada elemento.
            // Isso funciona mesmo quando a fila dá a volta
            // para o começo do array.
            int posicao = (inicio + i) % capacidade;

            cout << dados[posicao] << " ";
        }

        cout << endl;
    }
};

int main() {
    // Cria uma fila com capacidade para 5 elementos
    ArrayQueue fila(5);

    // Insere três elementos na fila
    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);

    fila.mostrar(); // Fila: 10 20 30

    // Consulta o primeiro elemento sem removê-lo
    cout << "Primeiro: " << fila.front() << endl;
    // Resultado: Primeiro: 10

    // Remove o primeiro elemento da fila
    cout << "Removido: " << fila.dequeue() << endl;
    // Resultado: Removido: 10

    fila.mostrar(); // Fila: 20 30

    // Insere mais um elemento no final
    fila.enqueue(40);

    fila.mostrar(); // Fila: 20 30 40

    cout << "Tamanho: " << fila.size() << endl;
    // Resultado: Tamanho: 3

    cout << "Fila vazia? "
         << (fila.isEmpty() ? "Sim" : "Nao") << endl;
    // Resultado: Fila vazia? Nao

    return 0;
}
