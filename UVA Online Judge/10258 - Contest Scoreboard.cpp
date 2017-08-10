#include <bits/stdc++.h>

using namespace std;

int ar[101][3];
int timeTable[101][10];
//             ^    ^
//           Team  Problem
set<int> showableTeams;

void sort2DArray(){
    qsort(ar, 101, sizeof(*ar),
        [](const void *arg1, const void *arg2)->int
        {
            int const *f = static_cast<int const*>(arg1);
            int const *s = static_cast<int const*>(arg2);
            // -1 -> F
            // +1 -> S
            if     (f[1] > s[1]) return -1; // Problems Solved
            else if(s[1] > f[1]) return +1;
            else if(f[2] < s[2]) return -1; // Penalty Time
            else if(s[2] < f[2]) return +1;
            else if(f[0] < s[0]) return -1; // Team Number
            else if(s[0] < f[0]) return +1;
        });
}

int main()
{
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    cin.ignore();
    bool programmeIsEnded = false;
    while(n --)
    {
        //set zero
        showableTeams.clear();
        memset(timeTable, 0, sizeof(timeTable[0][0]) * 1010);
        for(int i = 0;i < 101;i ++)
        {
            ar[i][0] = i;
            ar[i][1] = 0;
            ar[i][2] = 0;
        }

        while(true){
            string line;
            stringstream stream;
            if(! getline(cin,line))
            {
                //cout << 1 << endl;
                break;
            }

            if(line == ""){
                //cout << 2 << endl;
                break;
            }

            stream << line;
            int team,problem,time;
            char position;

            stream >> team >> problem >> time >> position;

            switch(position)
            {
                case 'C':
                    if(timeTable[team][problem] < 0)
                        break;
                    ar[team][1] ++;
                    ar[team][2] += time + 20 * timeTable[team][problem];
                    timeTable[team][problem] = -9999;
                    showableTeams.insert(team);
                    break;
                case 'I':
                    timeTable[team][problem] ++;
                    showableTeams.insert(team);
                    break;
                case 'R':
                case 'U':
                case 'E':
                    showableTeams.insert(team);
            }
        }
        sort2DArray();
        for(int i = 0;i < 101;i ++)
            if(showableTeams.find(ar[i][0]) != showableTeams.end())
                cout << ar[i][0] << " " << ar[i][1] << " " << ar[i][2] << endl;
        if(n > 0)
            cout << endl;
    }


    return 0;
}
