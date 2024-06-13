#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;

    priority_queue<int, vector<int>,greater<int>> heap;
    for(int i = 0; i < scoville.size(); ++i)
        heap.push(scoville[i]);

    while(heap.top() < K)
    {
        if(heap.size() < 2)
            return -1;

        int t1 = heap.top(); heap.pop();
        int t2 = heap.top(); heap.pop();
        
        int mix = t1 + t2*2;

        heap.push(mix);
        ++answer;
    }

    return answer;
}