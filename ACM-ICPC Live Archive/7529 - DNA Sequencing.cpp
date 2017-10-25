#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,m;
    while(cin >> k >> m){
        set<string> submited;

        if(k == 0 && m == 0)
            return 0;

        while(k --){
            int copies;
            string dna;
            cin >> copies >> dna;
            int picked = 0;
            while(dna.length() >= m){
                if(picked == copies)
                    break;
                if(submited.find(dna) == submited.end()){
                    submited.insert(dna);
                    picked ++;
                }
                dna.pop_back();
            }
        }

        cout << submited.size() << "\n";
    }
    return 0;
}
