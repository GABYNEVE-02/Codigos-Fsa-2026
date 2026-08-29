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

class Professor : virtual public Humano
{
    public:
        void Ensinar()
        {
            std::cout << "O Profesor esta dando aula" << std::endl;
        }
};

int main() {

    Estudante estudante;
    Professor Professor;

    estudante.Comer();
    estudante.Andar();
    estudante.Falar();
    Professor.Ensinar();
    estudante.Estudar();

    return 0;
}