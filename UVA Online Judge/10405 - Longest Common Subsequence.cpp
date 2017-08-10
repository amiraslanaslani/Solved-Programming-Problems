#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2;
    while(getline(cin, s1)){
        getline(cin, s2);

        int d[s1.size() + 1][s2.size() + 1];
        memset(d,0,sizeof(d));
        for(int i = 1;i <= s1.size();i ++){
            for(int j = 1;j <= s2.size();j ++){
                if(s1[i - 1] == s2[j - 1]){
                    d[i][j] = max(d[i - 1][j - 1] + 1, max(d[i - 1][j], d[i][j - 1]));
                }
                else {
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
                }
            }
        }
        cout << d[s1.size()][s2.size()] << endl;
    }
    return 0;
}
