#include <iostream>
#include <list>
#include <queue>

using namespace std;

#include "genListStack.h"
#include "genQueue.h"
#include "genArrayQueue.h"

int main() {
    LLStack<int> pilha;
    Queue<int> fila;
    ArrayQueue<int> filaArray;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);

    filaArray.enqueue(10);
    filaArray.enqueue(20);
    filaArray.enqueue(30);

    cout << "Pilha: ";
    while (!pilha.isEmpty()) {
        cout << pilha.pop() << ' ';
    }

    cout << "\nFila ligada: ";
    while (!fila.isEmpty()) {
        cout << fila.dequeue() << ' ';
    }

    cout << "\nFila com array: ";
    while (!filaArray.isEmpty()) {
        cout << filaArray.dequeue() << ' ';
    }

    cout << '\n';

    return 0;
}