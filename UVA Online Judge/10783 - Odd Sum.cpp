#include <iostream>

using namespace std;

int main()
{
    int t,a,b,i = 0;
    cin >> t;
    while(t --){
        int sum = 0;
        i ++;
        cout << "Case " << i << ": ";
        cin >> a >> b;
        if(a % 2 == 0)
            a ++;
        for(int f = a;f <= b;f += 2){
            sum += f;
        }
        cout << sum << endl;
    }
    return 0;
}
