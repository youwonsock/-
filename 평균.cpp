#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo
    int n = 0;
    float maxGrade = 0;
    float sum = 0;
    cin >> n;
    vector<float> grades(n);

    for(int i = 0; i < n; ++i)
        cin >> grades[i];

    for(int i = 0; i < n; ++i)
    {
        if(maxGrade < grades[i])
            maxGrade = grades[i];
    }

    for(int i = 0; i < n; ++i)
    {    
        grades[i] = grades[i] / maxGrade * 100;
        sum += grades[i];
    }

    cout << sum / n;

    return 0;
}