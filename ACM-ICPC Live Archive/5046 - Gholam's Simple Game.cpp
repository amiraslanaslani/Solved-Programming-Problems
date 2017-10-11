#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --){
        int n,m;
        cin >> m >> n;
        int tiles[m],pos,dir;
        for(int i = 0;i < m;i ++){
            cin >> tiles[i];

            if(tiles[i] == 2 || tiles[i] == 3)
                pos = i;
            if(tiles[i] == 2)
                dir = 1;
            if(tiles[i] == 3)
                dir = -1;

            if(tiles[i] == 0)
                tiles[i] = 1;
            else
                tiles[i] = 0;
        }
        int ytiles = 0;
        for(int i = 0;i <= n;i ++){
            if(tiles[pos] == 1)
                ytiles ++;
            pos += dir;
            if(pos == m || pos == -1){
                dir = - dir;
                pos += dir * 2;
            }
        }
        cout << ytiles << endl;
    }
    return 0;
}
