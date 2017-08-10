#include <iostream>

using namespace std;

int main()
{
    int c = 7490;
    int a[] = {1,1,2,5,10};

    long long int d[c + 1][5];
    for(int i = 0;i < c + 1;i ++)
        d[i][0] = 1;
    for(int i = 0;i < 5;i ++)
        d[0][i] = 1;

    for(int j = 1;j < 5;j ++)
        for(int i = 1;i <= c;i ++){
            if(a[j] > i)
                d[i][j] = d[i][j - 1];
            else {
                int tmp = a[j];
                d[i][j] = d[i][j - 1];
                while(tmp <= i){
                    d[i][j] += d[i - tmp][j - 1];
                    tmp += a[j];
                }
            }
        }

    while(cin >> c)
        cout << d[c / 5][4] << endl;


    return 0;
}
