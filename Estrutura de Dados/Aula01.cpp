#include <iostream>
#include <cstring>
#include <locale>

class Item {
    public:
        Item(const char *s = "", int i = 0, double d = 1) {
            std::strcpy(Nome,s);
            Idade = i;
            Dinheiro = d;
        }
        void Indentificar() {
            std::cout << "O nome é:" << Nome << std::endl;
            std::cout << "A idade é:" << Idade << std::endl;
            std::cout << "O dinheiro é:" << Dinheiro << std::endl;
        }
        void method2(int i, const char *s = "unknown") {
            Idade = i;
            std::cout << i << " received from " << s << std::endl;
        }

    protected:
        char Nome[20];
        int Idade;
        double Dinheiro;
};

int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    Item obj1("Senhor Pink",34,2000), obj2("Senhor Bronw",41,3000), obj3("Senhor White",40,4000);

    obj1.Indentificar();

    obj1.method2(123);

    obj1.method2(123, "Senhor ********");
}
