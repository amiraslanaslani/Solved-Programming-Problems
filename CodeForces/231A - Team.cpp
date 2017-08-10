#include <iostream>

using namespace std;

int main()
{
    int n,t1,t2,t3,sum = 0;
    cin >> n;
    while(n --){
        cin >> t1 >> t2 >> t3;
        if(t1 + t2 + t3 >= 2)
            sum ++;
    }
    cout << sum;
    return 0;
}
