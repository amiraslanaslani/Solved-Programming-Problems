#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s,n;
    while(true)
    {
        cin >> s >> n;
        if(s == 0 && n == 0)
            break;

        stack<int> digits;

        int y = n;
        int number_of_digits = 0;
        do {
             ++number_of_digits;
             digits.push(y % 10);
             y /= 10;
        } while (y);

        char t[2 * s + 3][(s + 2) * number_of_digits + number_of_digits - 1];

        for(int i = 0;i < 2 * s + 3;i ++)
            for(int j = 0;j < (s + 2) * number_of_digits + number_of_digits - 1;j ++)
                t[i][j] = ' ';

        int counter = 0;
        //cout << "T";
        while(! digits.empty())
        {
            int digit = digits.top();
            //cout << " X:" << digit;
            digits.pop();
            int shift = counter * (s + 3);
            switch(digit)
            {
            case 1:
                for(int i = 1;i < s + 1;i ++) // 6
                    t[i][shift + s + 1] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 5
                    t[i][shift + s + 1] = '|';
                break;
            case 2:
                for(int i = 1;i < s + 1;i ++) // 6
                    t[i][shift + s + 1] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 3
                    t[i][shift + 0] = '|';

                for(int i = 1;i < s + 1;i ++) // 1
                    t[0][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 7
                    t[s + 1][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 4
                    t[2 * s + 2][shift + i] = '-';
                break;
            case 3:
                for(int i = 1;i < s + 1;i ++) // 6
                    t[i][shift + s + 1] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 5
                    t[i][shift + s + 1] = '|';

                for(int i = 1;i < s + 1;i ++) // 1
                    t[0][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 7
                    t[s + 1][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 4
                    t[2 * s + 2][shift + i] = '-';
                break;
            case 4:
                for(int i = 1;i < s + 1;i ++) // 6
                    t[i][shift + s + 1] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 5
                    t[i][shift + s + 1] = '|';
                for(int i = 1;i < s + 1;i ++) // 7
                    t[s + 1][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 2
                    t[i][shift] = '|';
                break;
            case 5:
                for(int i = 1;i < s + 1;i ++) // 1
                    t[0][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 7
                    t[s + 1][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 4
                    t[2 * s + 2][shift + i] = '-';

                for(int i = 1;i < s + 1;i ++) // 2
                    t[i][shift] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 5
                    t[i][shift + s + 1] = '|';
                break;
            case 6:
                for(int i = 1;i < s + 1;i ++) // 1
                    t[0][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 7
                    t[s + 1][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 4
                    t[2 * s + 2][shift + i] = '-';

                for(int i = 2 + s;i < 2 * s + 2;i ++) // 3
                    t[i][shift + 0] = '|';
                for(int i = 1;i < s + 1;i ++) // 2
                    t[i][shift] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 5
                    t[i][shift + s + 1] = '|';
                break;
            case 7:
                for(int i = 1;i < s + 1;i ++) // 1
                    t[0][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 6
                    t[i][shift + s + 1] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 5
                    t[i][shift + s + 1] = '|';
                break;
            case 8:
                for(int i = 1;i < s + 1;i ++) // 1
                    t[0][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 7
                    t[s + 1][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 4
                    t[2 * s + 2][shift + i] = '-';

                for(int i = 1;i < s + 1;i ++) // 6
                    t[i][shift + s + 1] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 5
                    t[i][shift + s + 1] = '|';

                for(int i = 2 + s;i < 2 * s + 2;i ++) // 3
                    t[i][shift + 0] = '|';
                for(int i = 1;i < s + 1;i ++) // 2
                    t[i][shift] = '|';
                break;
            case 9:
                for(int i = 1;i < s + 1;i ++) // 1
                    t[0][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 7
                    t[s + 1][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 4
                    t[2 * s + 2][shift + i] = '-';

                for(int i = 1;i < s + 1;i ++) // 6
                    t[i][shift + s + 1] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 5
                    t[i][shift + s + 1] = '|';

                for(int i = 1;i < s + 1;i ++) // 2
                    t[i][shift] = '|';
                break;
            case 0:
                for(int i = 1;i < s + 1;i ++) // 1
                    t[0][shift + i] = '-';
                for(int i = 1;i < s + 1;i ++) // 4
                    t[2 * s + 2][shift + i] = '-';

                for(int i = 1;i < s + 1;i ++) // 6
                    t[i][shift + s + 1] = '|';
                for(int i = 2 + s;i < 2 * s + 2;i ++) // 5
                    t[i][shift + s + 1] = '|';

                for(int i = 2 + s;i < 2 * s + 2;i ++) // 3
                    t[i][shift + 0] = '|';
                for(int i = 1;i < s + 1;i ++) // 2
                    t[i][shift] = '|';
            }
            counter ++;
        }


        for(int i = 0;i < 2 * s + 3;i ++){
            for(int j = 0;j < (s + 2) * number_of_digits + number_of_digits - 1;j ++)
                cout << t[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
