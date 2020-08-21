#include <iostream>
using namespace std;
//source : https://www.geeksforgeeks.org/cc-preprocessors/
//macro definitation
#define LIMIT 5
//In the above program, when the compiler executes the word LIMIT it replaces it with 5.
//The word ‘LIMIT’ in the macro definition is called a macro template and ‘5’ is macro expansion.

#define AREA(length, breadth) (length * breadth)
/*We can see from the above program that, whenever the compiler finds AREA(l, b) 
in the program it replaces it with the statement (l*b) . Not only this, 
the values passed to the macro template AREA(l, b) will also be replaced in the statement (l*b).
 Therefore AREA(10, 5) will be equal to 10*5.*/
//#pragma startup function1 // THis feature will not support in GCC

void function1()
{
   cout<<"Function 1\n";
}

void function2()
{
    cout<<"Function 2";
}

void __attribute__((constructor)) function1(); 
void __attribute__((destructor)) function2();

int main()
{
    for (int i = 0; i < LIMIT; i++)
    {
        printf("%d \n", i);
    }

    cout << "The total area is : " << AREA(2, 3) << endl;
    return 0;
}