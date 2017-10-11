#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll n,s,d;
    ll m[150][150];
    while(cin >> n >> s >> d){
        if(n == 0 && s == 0 && d == 0)
            break;
        memset(m,1,sizeof(m));
        ll maxFloor = 0;
        while(n --){
            ll i;
            cin >> i;
            vector<ll> floors;
            while(i --){
                ll tmp;
                cin >> tmp;
                floors.push_back(tmp);
                if(tmp > maxFloor)
                    maxFloor = tmp;
            }
            for(ll i = 0;i < floors.size();i ++){
                for(ll j = 0;j < floors.size();j ++){
                    m[floors[i]][floors[j]] = m[floors[j]][floors[i]] = abs(floors[i] - floors[j]);
                }
            }
        }
        maxFloor ++;

        for (ll k = 0; k < maxFloor; k++){
            for (ll i = 0; i < maxFloor; i++){
                for (ll j = 0; j < maxFloor; j++){
                    if (m[i][j] > m[i][k] + m[k][j]){
                        m[i][j] = m[i][k] + m[k][j];
                        //prev[i][j] = k;
                    }
                }
            }
        }


        cout << m[s][d] << endl;

    }
    return 0;
}
