#include <iostream>
#include <vector>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void IsPrime(int num, int& count)
{
    int half = num / 2;
    for(int i = 2; i <= half; ++i)
    {
        if(num % i == 0)
            return;
    }

    ++count;
}

int main(void)
{
    fastIo

    int n, num;
    int count = 0;

    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> num;

        if(num > 2)
            IsPrime(num, count);
        else if(num == 2)
            ++count;
    }

    cout << count;

    return 0;
}