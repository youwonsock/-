
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    int n;
    cin >> n;
    vector<long long> arr(n, 0);

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<long long> sortedArr(arr);
    sort(sortedArr.begin(), sortedArr.end());
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

    for(int i = 0; i < n; ++i)
        cout << lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin() << " "; 

    return 0;
}