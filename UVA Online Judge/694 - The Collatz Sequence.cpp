#include <iostream>

using namespace std;

int main()
{
    int j = 0;
    while(true)
    {
        j ++;
        long long int A,limit;
        int i = 0;
        cin >> A >> limit;
        if(A < 0 && limit < 0)
            break;
        cout << "Case " << j << ": A = " << A;
        while(true){
            i ++;
            if(A == 1)
                break;
            if(A > limit)
            {
                i --;
                break;
            }
            if(A % 2 == 0)
                A /= 2;
            else
                A = 3 * A + 1;
        }
        cout << ", limit = " << limit << ", number of terms = " << i << endl;
    }
    return 0;
}
