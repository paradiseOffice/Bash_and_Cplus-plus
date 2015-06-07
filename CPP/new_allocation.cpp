#include <iostream>

using namespace std;

int main()
{
    // Request for memory space for an int
    int* pAge = new int;
    // Initialise the pointer
    cout << "Enter your swan's age: ";
    cin >> *pAge;

    // Use deref operation to access value
    cout << "Age " << *pAge << " is stored at " << hex << pAge << endl;

    delete pAge; // release memory

    return 0;
}

