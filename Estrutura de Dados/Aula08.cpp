#include <iostream>
using namespace std;

class IntSLLNode
{
    public:
        IntSLLNode()
        {
            proximo = 0;
        }

        IntSLLNode(int i, IntSLLNode * entrada = 0)
        {
            info = i;
            proximo = entrada;
        }

        int info;
        IntSLLNode *proximo;
};

int main()
{
    IntSLLNode Node2(20);
    IntSLLNode Node1(10,&Node2);

    cout << Node1.info << "\n";
    cout << Node1.proximo->info << "\n";

}