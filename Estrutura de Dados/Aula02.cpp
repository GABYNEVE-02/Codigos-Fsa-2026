#include <iostream>

template<class T>
class Item {
    public:
        T storage[50];
};

int main() {

    Item<int> intObj;
    Item<float> floatObj;
    
    std::cin >> intObj.storage[1];
    std::cin >> floatObj.storage[1];

    std::cout << intObj.storage[1] << std::endl;
    std::cout << floatObj.storage[1] << std::endl;

    return 0;
}