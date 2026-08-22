#include <iostream>

class  Mamifero
{
    public:

        void Comer()
        {
            std::cout << "O animal esta comendo" << std::endl;
        }

        void Andar()
        {
            std::cout << "O animal esta andando" << std::endl;
        }
};

class Humano : virtual public Mamifero
{
    public:
        void Falar()
        {
            std::cout << "O humano esta falando" << std::endl;
        }
};

class Estudante : virtual public Humano
{
    public:
        void Estudar()
        {
            std::cout << "O estudante esta estudando" << std::endl;
        }
};

int main() {

    Estudante estudante ;

    estudante.Comer();
    estudante.Andar();
    estudante.Falar();
    estudante.Estudar();

    return 0;
}