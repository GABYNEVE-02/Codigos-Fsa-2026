#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode 
{
    public:
        IntSLLNode()
        {
            proximo = 0;
        }
    
    IntSLLNode(int el, IntSLLNode *ptr = 0)
    {
        info = el;
        proximo = ptr;
    }

    int info;
    IntSLLNode *proximo;
};

class IntSLLList
{   
    public:

        IntSLLList()
        {
            topo = resto = 0;
        }

        ~IntSLLList();

        int isEmpty()
        {
            return topo == 0;
        }

        void addToTop(int);
        void addToResto(int);
        int deleteFromTop();  // remove o topo e retorna sua informaca
        int deleteFromResto(); // remove o resto e retorna sua informacao;
        void deleteNode(int);
        bool isInList(int) const;

    private:
        IntSLLNode *topo;
        IntSLLNode *resto;
};

#endif