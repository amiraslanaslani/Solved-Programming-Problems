#include <iostream>

using namespace std;

int main()
{
    long long int income;
    while(cin >> income){
        if(income == 0)
            return 0;
        float tax;
        if(income <= 1000000)
            tax = 1;
        else if(income <= 5000000)
            tax = 0.9;
        else
            tax = 0.8;
        printf("%d\n",(int)((float) income * tax));
    }
    return 0;
}
