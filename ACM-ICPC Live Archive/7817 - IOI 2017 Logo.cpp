#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;
    long long int id;
    while(true){
        map<long long int, float> scores;
        cin >> n;
        if(n == 0)
            return 0;
        while(n --){
            cin >> d;
            for(int i = 0;i < d;i ++){
                cin >> id;
                if(scores.find(id) == scores.end())
                    scores[id] = 0.0;
                if(i == 0)
                    scores[id] += 3.01;
                if(i == 1)
                    scores[id] += 2.0001;
                if(i == 2)
                    scores[id] += 1.000001;
            }
        }

        float maximum = 0;
        vector<long long int> mc;
        for(map<long long int, float>::iterator it = scores.begin(); it != scores.end();it ++){
            //printf("%lld : %f\n",it->first,it->second);
            if(it->second > maximum){
                maximum = it->second;
                mc.clear();
                mc.push_back(it->first);
            }
            else if(it->second == maximum){
                mc.push_back(it->first);
            }
        }

        for(int i = 0;i < mc.size();i ++){
            cout << mc[i];
            if(i != mc.size() - 1)
                cout << " ";
        }
        cout << '\n';
    }
    return 0;
}
