#include <iostream>
#include <vector>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n;
    cin >> n; 

    vector<int> arr(n + 2, 0);
    arr[1] = 1;
    arr[2] = 2;

    for(int i = 3; i <= n; ++i)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % 10,007;
    }

    cout << arr[n] << '\n';

    return 0;
}