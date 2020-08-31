// #include <iostream>
// using namespace std;

// //Node
// struct Node
// {
//     Node *leftChild;
//     Node *rightChild;
//     int data;
// };

// // Min Heap class
// class MinHeap
// {
// protected:
//     short size;
//     Node *heap;

// public:
//     MinHeap();
//     bool InsertHeap(int data);
// };

// //MinHeap constructor
// MinHeap::MinHeap()
// {
//     heap = NULL;
//     size = 0; // here we initialise size
// }

// bool MinHeap::InsertHeap(int data)
// {
//     Node *newNode, *temp = heap, *parent = NULL;
//     int tempData, index;
//     short mask = 0x80;

//     try
//     {
//         newNode = new Node;
//     }
//     catch (bad_alloc &e)
//     {
//         cerr << "Memory allocation error: " << e.what() << endl;
//         return false;
//     }

//     size++; // here we increment size by one (for each insertion)
//     index = size;
//     while (!(index & mask))
//         index <<= 1;
//     index <<= 1;

//     while (temp)
//     {
//         if (data > temp->data)
//         {
//             tempData = temp->data;
//             temp->data = data;
//             data = tempData;
//         }
//         parent = temp;

//         if (!(index & mask))
//             temp = temp->leftChild;
//         else
//             temp = temp->rightChild;

//         if (temp)
//             index <<= 1;
//     }

//     newNode->leftChild = NULL;
//     newNode->rightChild = NULL;
//     newNode->data = data;

//     if (!parent)
//     {
//         heap = newNode;
//         return true;
//     }

//     if (!(index & mask))
//         parent->leftChild = newNode;
//     else
//         parent->rightChild = newNode;
//     return true;
// }

// int main()
// {
//     MinHeap minHeap;

//     int arr[13] = {3, 6, 8, 1, 5, 9, 4, 2, 0, 7, 11, 14, 13};
//     printf("Helllo");
//     for (int i = 0; i < 13; i++)
//     {
//         minHeap.InsertHeap(arr[i]);
//     }

//     return 0;
// }