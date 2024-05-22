#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void Sort(int* arr)
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3 - 1 -i; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    fastIo

    int arr[3];

    while(true)
    {
        cin >> arr[0] >>  arr[1] >>  arr[2];

        if(arr[0] + arr[1] + arr[2] == 0)
            break;

        Sort(arr);

        arr[0] *= arr[0];
        arr[1] *= arr[1];
        arr[2] *= arr[2];

        if(arr[2] == arr[0] + arr[1])
            cout << "right" << "\n";
        else
            cout << "wrong" << "\n";
    }

    return 0;
}