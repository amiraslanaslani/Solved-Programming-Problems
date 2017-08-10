#include <iostream>

using namespace std;

long long  cycleLenght(long long  n){
    long long  i = 0;
    l2:
    i ++;
    if(n == 1)
        return i;
    if(n % 2 == 1)
        n = 3 * n + 1;
    else
        n = n / 2;
    goto l2;

}

int main()
{
    long long  i,j;
    while(cin >> i >> j){
        int ii = i,jj = j;
        if(j < i){
            swap(i,j);
        }
        long long mx = 0;
        for(long long x = i;x <= j;x ++){
            long long c = cycleLenght(x);
            if(c > mx)
                mx = c;
        }
        cout << ii << " " << jj << " " << mx << endl;
    }
}

