#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int maxW = 0, maxH = 0;

    for(int i = 0; i < sizes.size(); ++i)
    {
        maxW = max(maxW, min(sizes[i][0], sizes[i][1]));
        maxH = max(maxH, max(sizes[i][0], sizes[i][1]));
    }

    return maxW * maxH;
}