#include <iostream>
#include "/usr/include/c++/4.7/cstring"

using namespace std;

int main()
{
    char buffer[20] = {'\0'};
    cout << "Enter a line of text: " << endl;
    string lineEntered;
    cin >> lineEntered;
    if (lineEntered.strlen() < 20)
    {
        strcpy(buffer, lineEntered);
        cout << "Buffer contains: " << buffer << endl;
    }

    return 0;
}
