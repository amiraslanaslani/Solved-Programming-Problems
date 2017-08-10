#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,sa = 0,sb = 0,sd = 0;
    cin >> a >> b;
    for(int i = 1;i < 7;i ++)
    {
        int da = abs(a - i),db = abs(b - i);
        if(da < db)
            sa ++;
        else if(db < da)
            sb ++;
        else
            sd ++;
    }
    printf("%d %d %d",sa,sd,sb);
    return 0;
}
