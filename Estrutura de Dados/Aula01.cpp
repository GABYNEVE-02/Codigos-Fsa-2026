#include <iostream>
#include <cstring>


class Item {
    public:
        Item(const char *s = "", int i = 0, double d = 1) {
            std::strcpy(dataAttribute1,s);
            dataAttribute2 = i;
            dataAttribute3 = d;
        }
        void method1() {
            std::cout << dataAttribute1 << ' ' << dataAttribute2 << ' ' << dataAttribute3 << std::endl;
        }
        void method2(int i, const char *s = "unknown") {
            dataAttribute2 = i;
            std::cout << i << " received from " << s << std::endl;
        }

    protected:
        char dataAttribute1[20];
        int dataAttribute2;
        double dataAttribute3;
};


int main() {
    Item obj1("Senhor Pink",100,2000), obj2("Senhor Bronw",200,3000), obj3("Senhor White",300,4000);


    obj1.method1();


    obj1.method2(123);


    obj1.method2(123, "Senhor ********");
}
