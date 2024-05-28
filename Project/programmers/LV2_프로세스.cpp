#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;

    queue<int> q;
    vector<int> completeIDX;

    for(int i = 0; i < priorities.size(); ++i)
        q.push(i);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        if(priorities[current] == *max_element(priorities.begin(), priorities.end()))
        {
            priorities[current] = 0;
            completeIDX.push_back(current);
        }
        else
            q.push(current);
    }

    for(int i = 0; i < completeIDX.size(); ++i)
    {
        if(completeIDX[i] == location)
            answer = i+1;
    }

    return answer;
}