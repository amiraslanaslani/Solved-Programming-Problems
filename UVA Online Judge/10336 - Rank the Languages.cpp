#include <bits/stdc++.h>

using namespace std;

int W,H;
vector<string> mymap;
queue<int> DH;
queue<int> DW;
queue<char> DC;
vector< vector<int> > areas;

bool myCompare(vector<int> vec1,vector<int> vec2){
     if(vec1[1] == vec2[1])
     {
        if(vec1[0] < vec2[0])
            return true;
        else
            return false;
     }
     else if(vec1[1] > vec2[1])
        return true;
     else
        return false;
}

void CheckAround(int X0,int X1,char X2)
{
    if(X0 - 1 >= 0 && X2 == mymap[X0 - 1][X1]) // Up
    {
        DH.push(X0 - 1);
        DW.push(X1);
        DC.push(mymap[X0 - 1][X1]);
        mymap[X0 - 1][X1] = '0';
    }
    if(X1 - 1 >= 0 && X2 == mymap[X0][X1 - 1]) // Left
    {
        DH.push(X0);
        DW.push(X1 - 1);
        DC.push(mymap[X0][X1 - 1]);
        mymap[X0][X1 - 1] = '0';
    }
    if(X0 + 1 < H && X2 == mymap[X0 + 1][X1]) // Down
    {
        DH.push(X0 + 1);
        DW.push(X1);
        DC.push(mymap[X0 + 1][X1]);
        mymap[X0 + 1][X1] = '0';
    }
    if(X1 + 1 < W && X2 == mymap[X0][X1 + 1]) // Right
    {
        DH.push(X0);
        DW.push(X1 + 1);
        DC.push(mymap[X0][X1 + 1]);
        mymap[X0][X1 + 1] = '0';
    }
}

void CheckInAreasVector(char ch)
{
    bool fnd = false;
    int i;
    vector<int> tmpx;
    for(i = 0;i < areas.size();i++)
        if(areas[i][0] == ch)
        {
            fnd = true;
            break;
        }
    if(fnd)
        areas[i][1] ++;
    else
    {
        tmpx.push_back((int) ch);
        tmpx.push_back(1);
        areas.push_back(tmpx);
    }
}

void GetArea(int i,int j)
{
    CheckInAreasVector(mymap[i][j]);
    DH.push(i);
    DW.push(j);
    DC.push(mymap[i][j]);
    mymap[i][j] = '0';
    while(DH.size() > 0)
    {
        CheckAround(DH.front(),DW.front(),DC.front());
        DH.pop();
        DW.pop();
        DC.pop();
    }
}


int main()
{
    int n,X0,X1,X2,OP;
    bool X;
    string tmp;
    cin >> n;

    for(int YHN = 0;YHN < n;YHN++)
    {
        mymap.clear();
        areas.clear();
        cin >> H >> W;
        for(int i = 0;i < H;i ++)
        {
            cin >> tmp;
            mymap.push_back(tmp);
        }
        for(int i = 0;i < H;i ++)
        {
            for(int j = 0;j < W;j ++)
            {
                if(mymap[i][j] != '0')
                {
                    GetArea(i,j);
                }
            }
        }
        sort(areas.begin(),areas.end(),myCompare);
        cout << "World #" << YHN + 1 << endl;
        for(int i = 0;i < areas.size();i++)
            cout << (char)areas[i][0] << ": " << areas[i][1] << endl;
    }
    return 0;
}
