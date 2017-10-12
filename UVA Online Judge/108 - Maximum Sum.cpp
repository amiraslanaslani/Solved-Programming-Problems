#include <iostream>

using namespace std;
typedef long long int ll;

int M[100][100];
int S[100][100];

ll sum(int r1,int c1,int r2,int c2){
    if(r2 < 0 || c2 < 0)
        return 0;
    if(r1 == 0 && c1 == 0){
        return S[r2][c2];
    }
    else
        return sum(0,0,r2,c2) - sum(0,0,r1 - 1,c2) - sum(0,0,r2,c1 - 1) + sum(0,0,r1 - 1,c1 - 1);
}

int main()
{
    int n;

    while(cin >> n){
        for(int i = 0;i < n;i ++)
            for(int j = 0;j < n;j ++){
                //cin >> M[i][j];
                int tmp;
                cin >> tmp;
                M[i][j] = tmp;
                //cout << tmp << " ";
            }

        for(int i = 0;i < n;i ++)
            for(int j = 0;j < n;j ++){
                ll sum = 0;
                for(int k = 0;k <= i;k ++)
                    for(int l = 0;l <= j;l ++){
                        sum += M[k][l];
                    }

                S[i][j] = sum;
            }

        ll maxSum = -99999999;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++)
                for(int k = i;k < n;k ++)
                    for(int l = j;l < n;l ++){
                        if(sum(i,j,k,l) > maxSum)
                            maxSum = sum(i,j,k,l);
                    }
        }

        cout << maxSum << endl;
    }
    return 0;
}
