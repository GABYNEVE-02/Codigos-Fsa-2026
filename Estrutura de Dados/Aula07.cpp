#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // greater<T>
using namespace std;

template<class T>
void printVector(const char *nome, const vector<T>& vetor)
{
    cout << nome << " = (";

    if (vetor.size() == 0)
    {
        cout << ")\n";
        return;
    }

    typename vector<T>::const_iterator i = vetor.begin();

    for (; i != vetor.end() -1; i++)
        cout << *i << ',';
    cout << *i << ")\n";
}

bool f1(int n)
{
    return n < 4;
}

int main()
{
    vector<int> v1; // v1 esta vzio, tamanho = 0 e capacidade = 0
    printVector("v1",v1);
    for (int i = 1; i <= 5; i++)
    {
        v1.push_back(i); // push_back adiciona na ultima casa // v1 = (1,2,3,4,5), tamanho = 5 e capacidade = 5
    }
    printVector("v1",v1);

    vector<int> v2(3,7); // o (3,7) adiciona tres elementos de valor 7 //v2 (7,7,7) tamanho = 3 e capacidade = 3
    printVector("V2",v2);

    vector<int>::iterator i1 = v1.begin() + 1; // faz um interator apontando para o começo do v1
    vector<int> v3(i1,i1+2); // v3 = (2 3), tamanho = 2, capacidade = 2 
    v3.reserve(6); // v3 = (2 3), tamanho = 2, capacidade = 6 
    printVector("V3",v3);

    vector<int> v4(v1); // faz uma copia do vetor v1 // v4 = (1 2 3 4 5), tamanho = 5, capacidade = 5
    v4.resize(7); // v4 = (1 2 3 4 5 0 0), tamanho = 7, capacidade = 10 
    printVector("v4",v4);
    v4.resize(3); // v4 = (1 2 3), tamanho = 3, capacidade = 10
    printVector("V4 Resized",v4);
    v4.clear(); // v4 esta vazio, tamanho = 0, capacidade = 10 (!)
    printVector("V4 Clear",v4); // v4 esta vazio, tamanho = 0, capacidade = 10 (!) 

    vector<int> v5(5); // v5 = (0 0 0 0 0)
    v5[1] = v5.at(3) = 9; // v5 = (0 9 0 9 0) 
    printVector("v5",v5); 

    vector<int> v6(v1); // v6 = (1,2,3,4,5), tamanho = 5 e capacidade = 5
    v6.insert(v6.end(),v3[1]); // v6 = (1,2,3,4,5,3), tamanho = 5 e capacidade = 5
    printVector("v6",v6); 

    return 0;
}