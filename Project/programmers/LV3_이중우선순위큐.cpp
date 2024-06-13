#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) 
{
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2; 

    string c1, c2;
    int cnt = 0;
    
    for(int i = 0; i < operations.size(); ++i)
    {
        c1 = operations[i].substr(0, 1);
        c2 = operations[i].substr(2, operations[i].size());

        if (c1 == "I")
        {
            pq1.push(stoi(c2));
            pq2.push(stoi(c2));
            ++cnt;
        }
        else if (c1 == "D" && cnt > 0)
        {
            if(c2 == "-1")
                pq2.pop();
            else if(c2 == "1")
                pq1.pop();
            --cnt;

            if (cnt == 0)
            {
                while(!pq1.empty())
                    pq1.pop();
                while(!pq2.empty())
                    pq2.pop();
            }
        }
    }
    
    
    if(cnt == 0)
        return {0, 0};
    else
        return { pq1.top(), pq2.top() };
}