#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    int answersize = number.size() - k;
    int startidx = 0;
    
    for(int i = 0; i < answersize; ++i)
    {
        char maxint = number[startidx];
        int maxidx = startidx;

        for(int j = startidx; j <= k+i; j++)
        { 
            if(maxint < number[j])
            { 
                maxint = number[j];
                maxidx = j;
            }
        }

        startidx = maxidx + 1; 
        answer += maxint;
    }
    
    return answer;
}