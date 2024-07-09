#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    sort(people.begin(), people.end());

    int idx = 0;
    while(people.size() > idx)
    {
        int heavy = people.back(); people.pop_back();
        
        if(people[idx] + heavy <= limit)
        {
            answer++; 
            idx++;
        }
        else 
            answer++;
    }

    return answer;
}