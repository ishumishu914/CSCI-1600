#include <iostream>
using namespace std;

int main()
{
    int myInt = 23;
    int *myPointer;

    myPointer = &myInt;

    //display value and addres of the ordinary variable myInt
    cout << "value: myInt = " << myInt << "\t"
        << "address: &myInt = " << &myInt << endl;

    //display value and address of pointer variable
    cout << "value: *myPointer = " << *myPointer << "\t"
        << "address: myPointer = " << myPointer << endl;

    return 0;
}