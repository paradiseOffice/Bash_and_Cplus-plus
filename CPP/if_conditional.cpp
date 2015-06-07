#include <iostream>

using namespace std;

int main()
{
  cout << "Enter two numbers separated by a space: " << endl;
  int num1 = 0, num2 = 0;
  cin >> num1;
  cin >> num2;
  
  cout << "Enter \'m\' to multiply, anything else to add: ";
  char userSelection = '\0';
  cin >> userSelection;
  
  int result = 0;
  if ( userSelection == 'm' || userSelection == 'M' )
    result = num1 * num2;
  else
    result = num1 + num2;
  
  cout << "Result is: " << result << endl;
  
  return 0;
}
