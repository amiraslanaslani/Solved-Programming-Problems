#include <iostream>

using namespace std;

int main()
{
    int t = 1;
    while(true){
        int io,jo;
        cin >> io >> jo;
        if( io == 0 && jo == 0)
            return 0;
        if(t != 1)
            cout << endl;
        cout << "Field #" << t << ":" << endl;
        t ++;
        char m[io][jo];
        for(int i = 0;i < io;i ++)
            for(int j = 0;j < jo;j ++)
                cin >> m[i][j];

        for(int i = 0;i < io;i ++)
            for(int j = 0;j < jo;j ++){
                if(m[i][j] == '*')
                    continue;
                int c = 0;
                for(int pi = -1;pi <= 1;pi ++)
                    for(int pj = -1;pj <= 1;pj ++)
                        if(i + pi >= 0 &&
                           i + pi < io &&
                           j + pj >= 0 &&
                           j + pj < jo &&
                           m[i + pi][j + pj] == '*')
                            c ++;
                m[i][j] = c + '0';
            }

        for(int i = 0;i < io;i ++){
            for(int j = 0;j < jo;j ++)
                cout << m[i][j];
            cout << '\n';
        }
        //cout << '\n';
    }
    return 0;
}
