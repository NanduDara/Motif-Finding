#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main(void)
{
    string a;
    cin >> a;
    string b;
    int c;

    for(int i=0;i<5;i++)
    {
        b = a.substr(i,2);
        cout << b << " ";
    }
    cout << endl;
    return 0;
}
