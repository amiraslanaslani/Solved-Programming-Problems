#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    while(cin >> n >> m >> k){
        if(n == 0 && m == 0 && k == 0)
            return 0;
        int l = n - m - k;
        int minimum = n / 2 + 1;
        minimum -= m;
        if(minimum <= l){
            if(minimum < 0)
                minimum = 0;
            cout << minimum;
        }
        else
            cout << -1;
        cout << '\n';
    }
    return 0;
}
