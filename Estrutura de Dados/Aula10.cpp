#include <iostream>

template <class T>
class DoubleLinkedNode
{
public:
    T elemento;
    DoubleLinkedNode<T>* anterior;
    DoubleLinkedNode<T>* proximo;

    DoubleLinkedNode(T valor, DoubleLinkedNode<T>* ant,
                     DoubleLinkedNode<T>* prox)
    {
        elemento = valor;
        anterior = ant;
        proximo = prox;
    }
};

template <class T>
class DoubleLinkedList
{
private:
    DoubleLinkedNode<T>* inicio;
    DoubleLinkedNode<T>* fim;

public:
    // Construtor: cria uma lista vazia
    DoubleLinkedList()
    {
        inicio = nullptr;
        fim = nullptr;
    }

    // Adiciona um elemento no início da lista
    void adicionarNoInicio(T elemento)
    {
        DoubleLinkedNode<T>* novoNode =
            new DoubleLinkedNode<T>(elemento, nullptr, inicio); // Faz um novo nó apontar para o início atual da lista

        if (inicio != nullptr)
        {
            inicio->anterior = novoNode;
        }
        else
        {
            fim = novoNode;
        }

        inicio = novoNode;
    }

    void adicionarNoFim(T elemento)
    {
        DoubleLinkedNode<T>* novoNode =
            new DoubleLinkedNode<T>(elemento, fim, nullptr); // Faz um novo nó apontar para o fim atual da lista

        if (fim != nullptr)
        {
            fim->proximo = novoNode;
        }
        else
        {
            inicio = novoNode;
        }

        fim = novoNode;
    }

    void mostartlista()
    {
        DoubleLinkedNode<T>* p = inicio; // pega o primeiro nó da lista
        while (p != nullptr)
        {
            std::cout << p->elemento << " ";
            p = p->proximo;
        }
        std::cout << std::endl;
    }
};

int main()
{
    DoubleLinkedList<int> lista;

    lista.adicionarNoInicio(30);
    lista.adicionarNoInicio(20);
    lista.adicionarNoInicio(10);
    lista.adicionarNoFim(40);

    lista.mostartlista();

    return 0;
}