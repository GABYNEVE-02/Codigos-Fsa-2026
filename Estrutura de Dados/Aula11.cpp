#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <string>
#include <limits>
using namespace std;

void menu(list<string>& Historico);
void adicionarNaLista(list<string>& Lista);
void verHistorico(const list<string>& Lista);
void removerDaLista(list<string>& Lista);

void menu(list<string>& Historico)
{
    while (true)
    {
        int opcao;

        cout << "Progama de Historico" << endl;
        cout << "1-Adicionar" << endl;
        cout << "2-Remover" << endl;
        cout << "3-Ver historico" << endl;
        cout << "4-Sair" << endl;
        cin >> opcao ;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            system("cls");
            cout << "!!Opcao invalida!!" << endl;
            continue;
        }

        if (opcao == 1)
        {
            system("cls");
            adicionarNaLista(Historico);
            system("cls");
        }
        else if (opcao == 2)
        {
            system("cls");
            removerDaLista(Historico);
            system("cls");

        }
        else if (opcao == 3)
        {
            system("cls");
            verHistorico(Historico);
        }
        else if (opcao == 4)
        {
            system("cls");
            cout << "Terminal fechado" << endl;
            break;
        }
        else
        {
            system("cls");
            cout << "!!Opcao invalida!!" << endl;
        }
    }

}

void adicionarNaLista(list<string>& Lista)
{
    while (true)
    {
        system("cls");

        int opcao;

        system("cls");

        cout << "Adicionar link na lista" << endl;
        cout << "1-Inicio" << endl;
        cout << "2-Fim" << endl;
        cout << "3-Voltar" << endl;
        cin >> opcao;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            system("cls");
            cout << "!! Opcao invalida! !!" << endl;
            continue;
        }

        if (opcao == 1 || opcao == 2)
        {
            system("cls");

            string link;
            cout << "Digite o Link:" << endl;
            cin >> link;

            if (opcao == 1)
            {
                Lista.push_front(link);
            }
            else
            {
                Lista.push_back(link);
            }

            system("cls");
            cout << "Link adicionado com sucesso!" << endl;
        }
        else if (opcao == 3)
        {
            system("cls");
            break;
        }
        else
        {
            system("cls");
            cout << "!! Opcao invalida! !!" << endl;
        }
    }
}

void verHistorico(const list<string>& Lista)
{
    while (true)
    {
        int opcao;

        if (Lista.empty())
        {
            cout << "O historico esta vazio!" << endl;
        }
        else
        {
            cout << "\n--- Historico ---" << endl;

            for (const string& link : Lista)
            {
                cout << link << endl;
            }

            cout << "-----------------" << endl;
        }

        
        cout << "1-Voltar" << endl;
        cin >> opcao;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            system("cls");
            cout << "!!Opcao invalida!!" << endl;
            continue;
        }

        if (opcao == 1)
        {
            system("cls");
            break;
        }
        else
        {
            system("cls");
            cout << "!! Opcao invalida!!" << endl;
        }
    }
}

void removerDaLista(list<string>& Lista)
{
    
}

int main()
{
    list<string> Historico; //Lista sem nada
    system("cls");
    menu(Historico);
}
   

