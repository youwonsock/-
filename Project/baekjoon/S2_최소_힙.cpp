#include <iostream>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

inline void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class Heap
{
private:
    int* heap = nullptr;
    int heapCount = 0;

public:
    Heap() {};
    Heap(int size) { heap = new int[size+1]; }
    ~Heap() { delete[] heap; }

    void Push(int data)
    {
        heap[++heapCount] = data;
        int child = heapCount;
        int parent = child/2;

        while (1 < child && heap[parent] > heap[child])
        {
            swap(&heap[parent], &heap[child]);

            child = parent;
            parent = child/2;
        }
    }

    void Pop()
    {
        if(heapCount == 0)
        {
            cout << 0 << '\n';
            return;
        }

        int result = heap[1];

        swap(&heap[1], &heap[heapCount]);
        --heapCount;

        int parent = 1;
        int child = 2;
        if(child + 1 <= heapCount)
            child = (heap[child] < heap[child + 1]) ? child : child+1;

        while(child <= heapCount && heap[parent] > heap[child])
        {
            swap(&heap[parent], &heap[child]);

            parent = child;
            child = child * 2;
            if(child + 1 <= heapCount)
                child = (heap[child] < heap[child + 1]) ? child : child+1;
        }

        cout << result << '\n';
    }

};

int main(void)
{
    fastIo

    int n;
    cin >> n;
    Heap heap(n);

    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        if(x != 0)
            heap.Push(x);
        else
            heap.Pop();
    }

    return 0;
}
