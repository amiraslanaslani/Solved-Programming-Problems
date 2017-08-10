#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --){
        long long int a,b;
        cin >> a >> b;
        if(a < b)
            cout << '<';
        if(a > b)
            cout << '>';
        if(a == b)
            cout << '=';
        cout << endl;
    }
    return 0;
}
