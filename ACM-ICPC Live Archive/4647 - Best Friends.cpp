#include <bits/stdc++.h>

using namespace std;

int lays[150];

int getLayer(int n){
    int i;
    for(i = 0;;i ++){
        if(n < lays[i])
            break;
    }
    return i - 1;
}

int posV(int n){
    int i;
    for(i = 0;;i ++){
        if(n < lays[i])
            break;
    }
    return n - lays[i - 1];
}

int getDistV(int h,int pA, int pB){
    if(pB <= pA && pB >= pA-h)
        return 0;
    else
        return min(abs(pB - pA),abs(pB - (pA-h)));
}

int main()
{
    int tmp;
    for(int i = 1,j = 1;i < 11000;i += j,j ++){
        lays[j - 1] = i;
        tmp = j;
    }
    int a,b;
    while(cin >> a >> b){
        if(a == 0 && b == 0)
            break;
        if(a < b)
            swap(a,b);
        int lA = getLayer(a),lB = getLayer(b);
        int pA = posV(a), pB = posV(b);
        int h = abs(lA - lB);
        cout << h + getDistV(h,pA,pB) << endl;
    }
    return 0;
}
