#include <iostream>
#include <string>

using namespace std;

bool isNum(char c){
    return c <= '9' && c >= '1';
}

int main()
{
    int n;
    cin >> n;
    while(n --){
        string p;
        cin >> p;
        if(p.length() == 8 &&
           p[0] == p[1] &&
           isNum(p[0]) &&
           isNum(p[2]) &&
           isNum(p[3]) &&
           p[4] <= 'Z' && p[4] >= 'A' &&
           isNum(p[5]) &&
           isNum(p[6]) &&
           isNum(p[7])
           )
           cout << p << '\n';
    }
    return 0;
}
