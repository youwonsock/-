#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;

    int size = brown + yellow;

    for(int i = 3; i < size; ++i)
    {
        for(int j = 3; j < size; ++j)
        {
            if(i * j == size)
            {
                if(((i-2) * (j-2)) == yellow)
                    return {j,i};
            }
        }
    }

    return answer;

    // ???
    // int len = brown / 2 + 2;

    // int w = len - 3;
    // int h = 3;

    // while(w >= h){
    //     if(w * h == (brown + red)) break;

    //     w--;
    //     h++;
    // }

    // return vector<int>{w, h};
}