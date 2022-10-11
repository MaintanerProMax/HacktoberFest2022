#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a = 2, b = 3;
    
    cout << "Before swaping a = " <<
      a << " , b = " << b << endl;
    int temp;   
    temp = a;
    a = b;
    b = temp;
    cout << "After swaping a = " << a <<
            " , b = " << b << endl;
    return 0;
}
