#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) 
{
    string answer = "";

    vector<string> strNumbers;
    for(int i = 0; i < numbers.size(); ++i)
        strNumbers.push_back(to_string(numbers[i]));

    sort(strNumbers.begin(), strNumbers.end(), [](const string& first, const string& second) -> bool
    {
        return stoi(first+second) > stoi(second+first);
    });

    for(int i = 0; i < strNumbers.size(); ++i)
        answer += strNumbers[i];

    if(answer[0] == '0')
        answer = "0";

    return answer;
}