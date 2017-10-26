#include <bits/stdc++.h>

using namespace std;

int colorTable[16][3] = {
    {255,255,255},
    {192,192,192},
    {128,128,128},
    {0,0,0},
    {255,0,0},
    {128,0,0},
    {255,255,0},
    {128,128,0},
    {0,255,0},
    {0,128,0},
    {0,255,255},
    {0,128,128},
    {0,0,255},
    {0,0,128},
    {255,0,255},
    {128,0,128},
};
string colorName[] = {
    "White",
    "Silver",
    "Gray",
    "Black",
    "Red",
    "Maroon",
    "Yellow",
    "Olive",
    "Lime",
    "Green",
    "Aqua",
    "Teal",
    "Blue",
    "Navy",
    "Fuchsia",
    "Purple"
};

int main()
{
    int r,g,b;
    while(cin >> r >> g >> b){
        if(r == -1)
            return 0;
        int minid = -1;
        float minimum = 999999;
        for(int i = 0;i < 16;i ++){
            float dis = sqrt((r - colorTable[i][0]) * (r - colorTable[i][0]) + (g - colorTable[i][1]) * (g - colorTable[i][1]) + (b - colorTable[i][2]) * (b - colorTable[i][2]));
            if(dis < minimum){
                minimum = dis;
                minid = i;
            }
        }
        cout << colorName[minid] << '\n';
    }
    return 0;
}
