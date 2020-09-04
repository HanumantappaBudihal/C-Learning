#include"iostream"
#include"cstddef"
class node
{
    public:
    int value;
    node *leftAddress;
    node *rightAddress;
};

class minHeap
{
    public:

        node *rootNode;

        minHeap()
        {
            rootNode=NULL;
        }

        int heapHeight(node *tempNode)
        {
            if(tempNode==NULL)
                return 0;
            else
            {
                int leftSubheapHeight=heapHeight(tempNode->leftAddress);
                int rightSubheapHeight=heapHeight(tempNode->rightAddress);

                return std::max(leftSubheapHeight,rightSubheapHeight)+1;

            }
        }

        int checkGreater(node *tempTree1,node *tempTree2)
        {
	    if(heapHeight(tempTree1)>heapHeight(tempTree2))
                return 0;
            else
                return 1;
        }

        node* insertIntoTheHeap(int key, node *t)
        {
            int temp;
	        int insertLeft=checkGreater(t->leftAddress,t->rightAddress);
            if(t==NULL)
            {
                t=new node();
                t->value=key;
                t->leftAddress=t->rightAddress=NULL;
            }
            else if(key<t->value)
            {
                temp=t->value;
                t->value=key;
                if(!insertLeft)
                    insertIntoTheHeap(key,t->rightAddress);
                else
                    insertIntoTheHeap(key,t->leftAddress);
            }
            else
            {
                if(!insertLeft)
                    insertIntoTheHeap(key,t->rightAddress);
                else
                    insertIntoTheHeap(key,t->leftAddress);
            }

            return t;
        }

        void insertNode(int key)
        {
            rootNode=insertIntoTheHeap(key,rootNode);
        }

        void printNodes(node *tempNode)
        {
            std::cout<<"printNodes\n";
            if(tempNode==NULL)
                return;

            printNodes(tempNode->leftAddress);
            std::cout<<" "<<tempNode->value;

            printNodes(tempNode->rightAddress);
        }

        void print()
        {
            printNodes(rootNode);
        }
};

int main()
{
    minHeap heap;
    heap.insertNode(12);
    heap.insertNode(13);
    heap.insertNode(8);
    heap.insertNode(9);
    heap.insertNode(10);
    heap.print();
    return 0;
}
