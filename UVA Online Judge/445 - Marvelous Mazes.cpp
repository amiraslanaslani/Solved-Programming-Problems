#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    char c;
    while(cin.get(c))
    {
        if(c == '!' || c == '\n')
            cout << endl;
        else
        {
            if(c <= '9' && c >= '0')
                n += c - '0';
            else
            {
                if(c == 'b')
                    c = ' ';
                for(int i = 0;i < n;i ++)
                    cout << c;
                n = 0;
            }
        }
    }
    return 0;
}
