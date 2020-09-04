#include <limits>
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *parent;
    Node *leftChild;
    Node *rightChild;
};

class MinHeap
{
    Node *head;

public:
    MinHeap();
    void insert(int value); // inserts value d into the MinHeap
    void display();
    void inorderDisplay(Node *root);
};

MinHeap::MinHeap()
{
    head = NULL;
}

void MinHeap::insert(int value)
{
    // inserts value d into the MinHeap
    if (head == NULL)
    {
        head = new Node;
        head->value = value;
        head->parent = NULL;
        head->leftChild = NULL;
        head->rightChild = NULL;
    }
    else
    {
        Node *freePositionParent = head;
        Node *freePosition = new Node;
        int temp;

        //find the parent of a free position and then insert value d to this positon(a node that that has less than 2 childrend.)
        while (freePositionParent->leftChild != NULL && freePositionParent->rightChild != NULL)
        {
            //TODO : Need to decided to traverse either left or right
            if (rand() % 2 == 0)
            {
                freePositionParent = freePositionParent->leftChild;
            }
            else
            {
                freePositionParent = freePositionParent->rightChild;
            }
        }

        //if left child is NULL then insert to left child, else insert to right child.
        if (freePositionParent->leftChild == NULL)
        {
            freePositionParent->leftChild = freePosition;
        }
        else
        {
            freePositionParent->rightChild = freePosition;
        }

        //insert the new value to the position freePosition.
        freePosition->parent = freePositionParent;
        freePosition->value = value;
        freePosition->leftChild = NULL;
        freePosition->rightChild = NULL;

        while (freePositionParent != NULL && freePositionParent->value > freePosition->value)
        {
            //swap the value
            temp = freePositionParent->value;
            freePositionParent->value = freePosition->value;
            freePosition->value = temp;

            //set to one level higher
            freePosition = freePositionParent;
            freePositionParent = freePosition->parent;
        }
    }
}

void MinHeap :: inorderDisplay(Node *head)
{
    if(head==NULL)
    return;

    inorderDisplay(head->leftChild); 
        std :: cout<<" "<<head->value; 
    inorderDisplay(head->rightChild);
};

void MinHeap :: display()
{
    inorderDisplay(head);
};


int main()
{
    MinHeap minHeap;

    // example input
    int input[9] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 9; i++)
    {
        minHeap.insert(input[i]); //data is inserted into an MinHeap
    }

    minHeap.display();//User inorder to display the data
    return 0;
}