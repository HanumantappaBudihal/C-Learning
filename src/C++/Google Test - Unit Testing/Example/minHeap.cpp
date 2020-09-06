#include <iostream>

using namespace std;


class NODE
{
    public:
        int value;
        NODE *leftNode,*rightNode;
};

class TREE
{
        NODE *root;

    public:
        //To initialize a default NULL value to the root
        TREE()
        {
            root=NULL;
        }

        //To find depth of a subheap
        int findDepth(NODE *node)
        {
            if(node==NULL)
                return 0;
            else
            {
                int leftLength=findDepth(node->leftNode);
                int rightLength=findDepth(node->rightNode);

                return std::max(leftLength,rightLength)+1;
            }
        }

        //To do insertion of new values to the heap
        NODE* insert(int value,NODE* node)
        {
            if(node==NULL)
            {
                node=new NODE();
                node->value=value;
                node->leftNode=node->rightNode=NULL;
            }
            else
            {
                int temp=value;

                if(value<node->value)
                {
                    temp=node->value;
                    node->value=value;
                }

                if(findDepth(node->leftNode)>findDepth(node->rightNode))
                    node->rightNode=insert(temp,node->rightNode);
                else
                    node->leftNode=insert(temp,node->leftNode);
            }
            return node;
        }

        //To do insertion of new values to the heap
        void insert(int value)
        {
            root=insert(value,root);
        }

        //To traverse and print the value of all of the nodes in post order
        void traversePostOrderNodes(NODE *root)
        {
            if(root==NULL)
                return;
            else
            {
                traversePostOrderNodes(root->leftNode);
                traversePostOrderNodes(root->rightNode);

                cout<<root->value<<" ";
            }
        }

        //To traverse and print the value of all of the nodes in post order
        void traversePostOrderNodes()
        {
            cout<<"Post Ordered value of Heap nodes:"<<"\n";
            traversePostOrderNodes(root);
        }

        //To print value of the nodes having odd values in pre order
        void printOddNodesInPreOrder(NODE *root)
        {
            if(root==NULL)
                return;
            else
            {
                if((root->value%2)!=0)
                    cout<<root->value<<" ";

                printOddNodesInPreOrder(root->leftNode);
                printOddNodesInPreOrder(root->rightNode);
            }
        }

        //To print value of the nodes having odd values in pre order
        void printOddNodesInPreOrder()
        {
            cout<<"\n\nPre Ordered value of Odd Numbered nodes:"<<"\n";
            printOddNodesInPreOrder(root);
        }
};

int main()
{
    TREE tree;
    tree.insert(1);
    tree.insert(12);
    tree.insert(3);
    tree.insert(17);
    tree.insert(8);
    tree.insert(15);
    tree.traversePostOrderNodes();
    tree.printOddNodesInPreOrder();
    
    return 0;
}