#include <iostream>

using namespace std;

int main()
{
    long long int x,y;
    while(cin >> x >> y)
        if(y- x > 0)
            cout << y - x << endl;
        else
            cout << x - y << endl;
    return 0;
}
