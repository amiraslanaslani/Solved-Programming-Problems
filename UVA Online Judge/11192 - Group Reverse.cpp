#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(true){
        cin >> n;
        if(! n)
            break;
        string str;
        cin >> str;
        int splitS = str.size() / n;

        string lastStr = "";
        for(int i = 0;i < n;i ++)
        {
            string tmp = str.substr(i * splitS,splitS);
            reverse(tmp.begin(),tmp.end());
            lastStr += tmp;
        }
        cout << lastStr << endl;
    }
}
