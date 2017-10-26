#include <iostream>

using namespace std;

int main()
{
    int m,n;
    while(cin >> m >> n){
        if(m == 0 && n == 0)
            return 0;
        int c[m];
        for(int i = 0;i < m;i ++)
            cin >> c[i];
        int counter = 0;
        for(int i = 0;i < n;i ++){
            bool canBee = true;
            for(int j = 0;j < m;j ++){
                int t;
                cin >> t;
                if(t > c[j]){
                    canBee = false;
                }
            }
            if(canBee)
                counter ++;
        }
        cout << counter << '\n';
    }
    return 0;
}
