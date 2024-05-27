#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void QuickSort(int* arr, int first, int last)
{
    if(first >= last)
        return;

    int pivot = first;

    int leftIDX = first + 1;
    int rightIDX = last;
    int temp;

    while(leftIDX <= rightIDX)
    {
        while (arr[leftIDX] < arr[pivot] && leftIDX <= last)
            ++leftIDX;

        while (arr[rightIDX] >= arr[pivot] && rightIDX > first)
            --rightIDX;
        
        if(leftIDX >= rightIDX)
            break;

        temp = arr[leftIDX];
        arr[leftIDX] = arr[rightIDX];
        arr[rightIDX] = temp;
    }

    temp = arr[rightIDX];
    arr[rightIDX] = arr[pivot];
    arr[pivot] = temp;

    QuickSort(arr, first, rightIDX - 1);
    QuickSort(arr, rightIDX + 1, last);
}

int main(void)
{
    fastIo

    int n;
    cin >> n;
    int* arr = new int[n];

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    QuickSort(arr, 0, n-1);

    for(int i = 0; i < n; ++i)
        cout << arr[i] << "\n";

    return 0;
}
