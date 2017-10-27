#include <bits/stdc++.h>

using namespace std;

typedef long int coord_t;
typedef long int coord2_t;

struct Point {
    coord_t x,y;
    bool operator < (const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

coord2_t cross(const Point &O,const Point &A,const Point &B){
    return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P){
    int n = P.size(), k = 0;
    vector<Point> H(2*n);
    sort(P.begin(),P.end());
    for(int i = 0;i < n;++ i){
        while(k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0)
            k --;
        H[k ++] = P[i];
    }
    for(int i = n-2,t = k+1;i >= 0;i --){
        while(k >= t && cross(H[k-2], H[k-1], P[i]) <= 0)
            k --;
        H[k ++] = P[i];
    }
    H.resize(k);
    return H;
}

int main()
{
    int n;
    while(cin >> n){
        if(n == 0)
            return 0;
        vector<Point> points;
        while(n --){
            int x,y;
            cin >> x >> y;
            Point p;
            p.x = x;
            p.y = y;
            points.push_back(p);
        }

        vector<Point> after = convex_hull(points);

        int as = 0,bs = 0; // a + b(2^.5)
        Point pr = after[0];
        for(int i = 1;i < after.size();i ++){
            Point cu = after[i];
            int dx = abs(cu.x - pr.x);
            int dy = abs(cu.y - pr.y);
            if(dx <= dy)
                swap(dx,dy);
            as += dx - dy;
            bs += dy;
            pr = cu;
        }
        printf("%d %d\n",as,bs);
    }
    return 0;
}
