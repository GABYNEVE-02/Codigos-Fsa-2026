#include <iostream>
#include <intSLLst.h>

IntSLLList::~IntSLLList()
{
    for (IntSLLNode *p; !isEmpty(); )
    {
        p = topo->proximo;
        delete topo;
        topo = p;
    }
}

void IntSLLList::addToTop(int el)
{
    topo = new IntSLLNode(el, topo);
    if (resto == 0)
        resto = topo;
}

int main()
{
    IntSLLList lista;

    lista.addToTop(10);
    lista.addToTop(20);
    lista.addToTop(30);

    IntSLLNode *p = lista.topo;

    while (p != 0)
    {
        std::cout << p->info << " ";
        p = p->proximo;
    }

    std::cout << std::endl;

    return 0;
}