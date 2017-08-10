#include <bits/stdc++.h>

using namespace std;

char change_case (char c) {
    if (isupper(c))
        return tolower(c);
    else
        return toupper(c);
}

string removeNumbers(string tmp)
{
    for(int j = 0;j < tmp.size();j++)
    {
        if(tmp[j] <= 57 && tmp[j] >= 48)
        {
           tmp.erase(tmp.begin()+j);
            j --;
        }
    }
    return tmp;
}

int main()
{
    int n;
    string a,b,tmp;
    bool num,caps;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        cin >> a >> b;
        num = caps = false;
        cout << "Case " << i + 1 << ": ";
        if(a == b)
        {
            cout << "Login successful.";
        }
        else
        {
            if(removeNumbers(a) == b)
                cout << "Wrong password. Please, check your num lock key.";
            else
            {
                tmp = a;
                transform(tmp.begin(), tmp.end(), tmp.begin(), change_case);
                if(tmp == b)
                    cout << "Wrong password. Please, check your caps lock key.";
                else
                {
                    tmp = removeNumbers(a);
                    transform(tmp.begin(), tmp.end(), tmp.begin(), change_case);
                    if(tmp == b)
                        cout << "Wrong password. Please, check your caps lock and num lock keys.";
                    else
                        cout << "Wrong password.";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
