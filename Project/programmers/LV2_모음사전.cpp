#include <string>
#include <vector>

using namespace std;

int answer = 0;
int cnt = -1;
string target = "";
string aeiou = "AEIOU";

void DFS(string word)
{
    ++cnt;
    
    if(word == target)
    {
        answer = cnt;
        return;
    }

    if(word.length() >= 5)
        return;
    
    for(int i = 0; i < 5; ++i)
        DFS(word + aeiou[i]);
}

int solution(string word) 
{
    target = word;
    DFS("");

    return answer;
}