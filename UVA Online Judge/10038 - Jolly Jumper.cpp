#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> defs;
        int oneAgo = -1,counter = n;
        bool x = false;
        while(n --)
        {
            int tmp;
            cin >> tmp;
            if(x)
                defs.push_back(abs(oneAgo - tmp));
            oneAgo = tmp;
            x = true;
        }
        sort(defs.begin(),defs.end());
        bool jolly = true;
        for(int i = 1;i < counter;i ++)
        {
            //cout << defs[i - 1] << " ";
            if(defs[i - 1] != i)
            {
                jolly = false;
                //break;
            }
        }
        if(jolly)
            cout << "Jolly";
        else
            cout << "Not jolly";
        cout << endl;
    }
    return 0;
}
