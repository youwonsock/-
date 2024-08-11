#include <iostream>
#include <vector>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n;
    cin >> n;

    vector<vector<int>> triangle(n, vector<int>(n));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < i+1; ++j)
        {
            cin >> triangle[i][j];
        }
    }

    for(int i = n-1; i > 0; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            int bigger = triangle[i][j] > triangle[i][j+1] ? triangle[i][j] : triangle[i][j+1];
            triangle[i-1][j] += bigger;
        }
    }

    cout << triangle[0][0];

    return 0;
}
