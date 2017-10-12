#include <bits/stdc++.h>

using namespace std;

vector<vector<char> > chars= {
    {'a','b','c'},
    {'d','e','f'},
    {'g','h','i'},
    {'j','k','l'},
    {'m','n','o'},
    {'p','q','r','s'},
    {'t','u','v'},
    {'w','x','y','z'},
    {'A','B','C'},
    {'D','E','F'},
    {'G','H','I'},
    {'J','K','L'},
    {'M','N','O'},
    {'P','Q','R','S'},
    {'T','U','V'},
    {'W','X','Y','Z'}
};

char whileOnChar(vector<char> v, int pos, int p){
    for(int i = 0;i <= p;i ++){
        if(pos == 0)
            pos = v.size() - 1;
        else
            pos --;
    }
    return v[pos];
}

char Decrypt(char c, int p){
    for(int i = 0;i < chars.size();i ++)
        if(find(chars[i].begin(),chars[i].end(),c) != chars[i].end()){
            int pos = distance(chars[i].begin(), find(chars[i].begin(), chars[i].end(), c));
            return whileOnChar(chars[i],pos,p);
        }
    return '-';
}

int main()
{

    string str;
    while(cin >> str){
        if(str == "#")
            break;
        for(int i = 0;i < str.length();i ++)
            str[i] = Decrypt(str[i],i);
        cout << str << endl;
    }

    return 0;
}
