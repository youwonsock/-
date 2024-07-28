
#include <iostream>
#include <vector>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int white = 0;
int blue = 0;

void QuadTree(vector<vector<int>>& paper, int size, int x, int y)
{
    int blueCount = 0;

    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            if(paper[y + i][x + j] == 1)
                ++blueCount;
        }
    }

    if(blueCount == (size*size))
    {
        ++blue;
        return;
    }
    else if(blueCount == 0)
    {
        ++white;
        return;
    }
    
    if(size > 1)
    {
        int temp = size/2;

        QuadTree(paper, temp, x, y);
        QuadTree(paper, temp, x + temp, y);
        QuadTree(paper, temp, x, y + temp);
        QuadTree(paper, temp, x + temp, y + temp);
    }
}

int main(void)
{
    fastIo

    int n;
    cin >> n;

    vector<vector<int>> paper(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            cin >> paper[i][j];
    }

    QuadTree(paper, n, 0, 0);

    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}
