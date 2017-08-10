#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1,n2,c = 0;
    while(true){
        c ++;
        cin >> n1 >> n2;
        if(n1 == n2 && n1 == 0)
            break;
        int s1[n1],s2[n2];
        for(int i = 0;i < n1;i ++)
            cin >> s1[i];
        for(int i = 0;i < n2;i ++)
            cin >> s2[i];

        int d[n1 + 1][n2 + 1];
        memset(d,0,sizeof(d));

        for(int i = 1;i <= n1;i ++)
            for(int j = 1;j <= n2;j ++){
                if(s1[i - 1] == s2[j - 1])
                    d[i][j] = max(1 + d[i - 1][j - 1],max(d[i - 1][j], d[i][j - 1]));
                else
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }

        cout << "Twin Towers #" << c << endl << "Number of Tiles : " << d[n1][n2] << endl << endl;
    }
    return 0;
}
