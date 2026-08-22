#include <iostream>

template<class T>
class Item {
    public:
        T storage[50];

    void trocar(T& N1, T& N2)
    {
        T Temporaria = N1;
        N1 = N2;
        N2 = Temporaria;
        std::cout << "Fez a troca" << std::endl;
        std::cout << N1 << std::endl;
        std::cout << N2 << std::endl;

    }
};

int main() {

    Item<int> intObj1;
    Item<int> intObj2;

    std::cin >> intObj1.storage[1];
    std::cin >> intObj2.storage[1];

    intObj1.trocar(intObj1.storage[1], intObj2.storage[1]);

    std::cout << "Após a troca:" << std::endl;

    return 0;
}