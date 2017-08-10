#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,tmp;
    vector<int> Ms,Ns;
    while(true){
        Ms.clear();
        Ns.clear();
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        while(n --)
        {
            cin >> tmp;
            Ns.push_back(tmp);
        }
        while(m --)
        {
            cin >> tmp;
            Ms.push_back(tmp);
        }

        sort(Ms.begin(),Ms.end(),greater<int>());
        sort(Ns.begin(),Ns.end(),greater<int>());

        bool doomed = false;
        int sum = 0;
        while(!Ns.empty())
        {
            if(Ms.size() < Ns.size() || Ms.size() == 0){
                doomed = true;
                break;
            }
            if(Ms.back() >= Ns.back())
            {
                sum += Ms.back();
                Ms.pop_back();
                Ns.pop_back();
            }
            else
                Ms.pop_back();
        }
        if(doomed)
            cout << "Loowater is doomed!" << endl;
        else
            cout << sum << endl;
    }
    return 0;
}
