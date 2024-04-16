#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) 
{
    vector<int> answer;
    int min = 0;
    bool isExist = false; 

    for (int i = 0; i < queries.size(); ++i)
    {
        min = 1000000;
        isExist = false;
        for (int j = queries[i][0]; j < queries[i][1]; ++j)
        {
            if (queries[i][2] < arr[j] && arr[j] < min)
            {
                min = arr[j];
                isExist = true;
            }
        }

        if (!isExist)
            min = -1;

        answer.push_back(min);
    }

    return answer;
}

int main(void) 
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);

    // Code here
    solution({ 0,1,2,4,3 }, { {0, 4, 2},{0, 3, 2},{0, 2, 2} });
    
    return 0;
}