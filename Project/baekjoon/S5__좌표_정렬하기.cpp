#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Point
{
public:
    Point(int x, int y) : x(x), y(y) { }

    void Print()
    {
        cout << x << " " << y << "\n";
    }

public:
    int x = 0;
    int y = 0;
};

bool Compare(Point& a, Point& b)
{
    if(a.x > b.x)
        return false;
    else if (a.x == b.x)
    {
        if(a.y > b.y)
            return false;
        else
            return true;
    }
    
    return true;
}

int main(void)
{
    fastIo

    int n, x, y;
    cin >> n;
    vector<Point> points;

    for(int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        points.emplace_back(x,y);
    }

    sort(points.begin(), points.end(), Compare);

    for(int i = 0; i < n; ++i)
        points[i].Print();

    return 0;
}