/*Description:
??Can the highest degree be 4
1)ask for coefficients til degree 5
2)ignore all the 0s
3)display the original function neatly
4)solve for x

*/

#include <iostream>
#include <cmath>
using namespace std;

double get_function(double arr[6], double num);
double get_derivitive(double der[5], double num);

int main()
{
    double coef[6]={0}, deriv[5]={0};
    double x;
    char choice = 'y';

    cout << "Welcome to Newtons Method! Here is a program were you wright a polynomial up to the degree 4";

    for(int i=5; i>=0; i--)//starts from 5
    {
        cout << "\nWhat is the coefficient for x^" << i << ": ";
        cin >> coef[i];
    }
    cout << "\nEquation: ";
    while(choice == 'y' || choice == 'Y')
    {
      for(int i = 5; i >= 0; i--)
      {
          if(coef[i] != 0)//Checks for 0 coef
        {
          if(i == 0)//constant number
          {
            if(coef[i] > 0)
            {
              cout << coef[i];
            }
            else if(coef[i] < 0)
            {
              cout << coef[0];
            }
          }
          else//rest coef
            cout<< coef[i] << "x^" << i << " + ";
        }
      } 
      cout << " = 0\n\nIs this equation wrong?(y): ";
      cin >> choice;
    }
    cout << "\nWhat is your initial guess: ";
    cin >> x;

   for(int i = 0; i < 5; i++)
        deriv[i-1] = coef[i] * i;

   for(int i = 0; i < 10; i++)
        x = x - (get_function(coef, x)/(get_derivitive(deriv, x) ));

   cout << x;

   return 0;
}

double get_function(double arr[6], double num)
{
    double sum = arr[5];

   for(int i = 0; i < 5; i++)
        sum += arr[i] * pow(num, i);

   return sum;
}
double get_derivitive(double deriv[5], double num)
{
    double sum = deriv[4];

   for(int i = 0; i < 4; i++)
        sum += deriv[i] * pow(num,i);

   return sum;
}