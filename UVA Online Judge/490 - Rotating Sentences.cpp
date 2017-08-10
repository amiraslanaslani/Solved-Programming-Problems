#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> myVector;
    string mySentence;
    int sentenceCounter = 0,printCounter = 0,maxSentenceSize = 0;
    while(getline(cin,mySentence))
    {
        myVector.push_back(mySentence);
        if(mySentence.size() > maxSentenceSize)
            maxSentenceSize = mySentence.size();
        sentenceCounter ++;
    }
    for(int j = 0;j < maxSentenceSize;j ++)
    {
        for(int i = sentenceCounter - 1,k = 1;i >= 0;i --,k ++)
        {
            if(myVector[i].size() < j + 1)
                cout << " ";
            else
                cout << myVector[i][printCounter];
        }
        cout << endl;
        printCounter ++;
    }
    return 0;
}
