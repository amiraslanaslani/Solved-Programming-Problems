#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c;
    cin >> c;
    while(c --){
        int n,m;
        cin >> n >> m;
        n = ceil( (float) (n - 2) / 3 );
        m = ceil( (float) (m - 2) / 3 );
        cout << n * m << endl;
    }
    return 0;
}
