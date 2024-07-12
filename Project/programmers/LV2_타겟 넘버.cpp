#include <string>
#include <vector>

using namespace std;

int resultNum = 0;
int answer = 0;

void DFS(const vector<int>& numbers, int currentNum, int idx)
{
    if(idx >= numbers.size())
    {
        if(currentNum == resultNum)
            ++answer;

        return;
    }

    DFS(numbers, currentNum + numbers[idx], idx + 1);
    DFS(numbers, currentNum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) 
{
    resultNum = target; 

    DFS(numbers, 0, 0);

    return answer;
}