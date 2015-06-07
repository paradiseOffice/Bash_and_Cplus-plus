#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter your name: ";
    string name;
    cin >> name;

    // reserve a space for null
    int charBuffer = name.length() + 1;

    // request memory
    char* copyOfName = new char [charBuffer];
    // strcpy copies from a null - terminated string
    strncpy(copyOfName, name.c_str());

    cout << "Dynamically allocated buffer contains: " << copyOfName << endl;

    // delete buffer
    delete[] copyOfName;

    return 0;
}

