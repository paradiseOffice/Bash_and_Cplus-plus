#include <iostream>
using namespace std;

int main()
{
    int age = 30;
    int* pInteger = &age; // pointer to an int, initialised to &age (address)

    cout << "Integer age is at: 0x" << hex << pInteger << endl;
    cout << "Age is: " << age << endl;

    return 0;
}

