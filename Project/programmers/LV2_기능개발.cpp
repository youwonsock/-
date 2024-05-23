#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> jobQueue;

    for(int i = 0; i < progresses.size(); ++i)
    {    
        int left = ceil((100.0f - progresses[i]) / speeds[i]) ;
        jobQueue.push(left);
    }

    while(!jobQueue.empty())
    {
        int count = 1;
        int current = jobQueue.front();
        jobQueue.pop();

        while(!jobQueue.empty())
        {
            if(jobQueue.front() <= current)
            {
                ++count;
                jobQueue.pop();
            }
            else
                break;
        }

        answer.push_back(count);
    }

    return answer;
}
