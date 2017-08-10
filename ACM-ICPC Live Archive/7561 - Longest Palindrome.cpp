#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Tcase;
    cin>>Tcase;
    while(Tcase--){
        int n,aa = 0,bb = 0,ab = 0,ba = 0,aap = 0,bbp = 0,abp = 0;
        cin>>n;
        while(n--){
            string s;
            cin >> s;
            if(s == "aa"){
                aa ++;
            }
            if(s == "ab"){
                ab ++;
            }
            if(s == "ba"){
                ba ++;
            }
            if(s == "bb"){
                bb ++;
            }
        }
        aap = aa / 2;
        aa = aa % 2;

        bbp = bb / 2;
        bb = bb % 2;

        if(ab < ba)
            abp = ab;
        else
            abp = ba;

        for(int i = 0;i < aap;i ++)
            cout << "aa";
        for(int i = 0;i < abp;i ++)
            cout << "ab";
        for(int i = 0;i < bbp;i ++)
            cout << "bb";

        if(aa)
            cout << "aa";
        else if(bb)
            cout << "bb";


        for(int i = 0;i < bbp;i ++)
            cout << "bb";
        for(int i = 0;i < abp;i ++)
            cout << "ba";
        for(int i = 0;i < aap;i ++)
            cout << "aa";

        cout << endl;
    }

    return 0;
}

