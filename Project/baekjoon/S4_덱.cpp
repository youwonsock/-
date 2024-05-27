// 긁어 온거
#include <iostream>
#include <string>
 
using namespace std;
 
const int MX = 1000000;
int deque_arr[2 * MX + 1];
int head = MX, tail = MX;
 
int empty(int dat[]) {
    if (head == tail) return 1; // 덱이 비어 있는 경우
    else return 0; // 덱이 비어 있지 않은 경우
}
 
void push_front(int deque_arr[], int data) {
    deque_arr[--head] = data;
}
 
void push_back(int deque_arr[], int data) {
    deque_arr[tail++] = data;
}
 
int pop_front(int deque_arr[]) {
    if (empty(deque_arr)) return -1;
    return deque_arr[head++];
}
 
int pop_back(int deque_arr[]) {
    if (empty(deque_arr)) return -1;
    return deque_arr[--tail];
}
 
int size(int deque_arr[]) {
    return tail - head;
}
 
int front(int deque_arr[]) {
    if (empty(deque_arr)) return - 1;
    return deque_arr[head];
}
 
int back(int deque_arr[]) {
    if (empty(deque_arr)) return -1;
    return deque_arr[tail - 1];
}
 
int main() {
    int n;
    cin >> n;
    
    string command;
    int command_num;
 
    for (int i = 0; i < n; i++) {
        cin >> command;
 
        if (command == "push_front") {
            cin >> command_num;
            push_front(deque_arr, command_num);
        }
        else if (command == "push_back") {
            cin >> command_num;
            push_back(deque_arr, command_num);
        }
        else if (command == "pop_front") {
            cout << pop_front(deque_arr) << endl;
        }
        else if (command == "pop_back") {
            cout << pop_back(deque_arr) << endl;
        }
        else if (command == "size") {
            cout << size(deque_arr) << endl;
        }
        else if (command == "empty") {
            cout << empty(deque_arr) << endl;
        }
        else if (command == "front") {
            cout << front(deque_arr) << endl;
        }
        else if (command == "back") {
            cout << back(deque_arr) << endl;
        }
    }
    
    return 0;
}

// stl 자료구조 덱을 직접 구현(10866 테스트 케이스는 통과, 문제는 출력 초과)
// #include <bits/stdc++.h>

// using namespace std;
// #define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// #define DEQUE_ARR_SIZE 5

// class Deque
// {
// public:
//     Deque()
//     {
//         ptrArr = new int*[ptrArrSize];    

//         for(int i = 0; i < ptrArrSize; ++i)
//             ptrArr[i] = new int[DEQUE_ARR_SIZE];

//         front = DEQUE_ARR_SIZE * ptrArrSize / 2 + ptrArrSize / 2;
//         back = front;
//     }
//     ~Deque()
//     {
//         for(int i = 0; i < ptrArrSize; ++i)
//             delete[] ptrArr[i];

//         delete[] ptrArr;
//     }

//     int Commend(string commend)
//     {
//         if(commend == "push_front")
//             PushFront();
//         else if (commend == "push_back")
//             PushBack();
//         else if (commend == "pop_front")
//             PopFront();
//         else if (commend == "pop_back")
//             PopBack();
//         else if (commend == "size")
//             Size();
//         else if (commend == "empty")
//             Empty();
//         else if (commend == "front")
//             Front();
//         else if (commend == "back")
//             Back();
//     }

// private:
//     void PushFront()
//     {
//         int n;
//         cin >> n;

//         if(++front >= ptrArrSize * DEQUE_ARR_SIZE - 1 )
//         {
//             int** tempPtrArr = new int*[++ptrArrSize];

//             memcpy(tempPtrArr, ptrArr, sizeof(int*) * (ptrArrSize - 1));
//             tempPtrArr[ptrArrSize - 1] = new int[DEQUE_ARR_SIZE];

//             ptrArr = tempPtrArr;
//         }

//         ptrArr[front / ptrArrSize][front % DEQUE_ARR_SIZE] = n;
//     }
//     void PushBack()
//     {
//         int n;
//         cin >> n;

//         if(back < 0 )
//         {
//             int** tempPtrArr = new int*[++ptrArrSize];

//             memcpy(tempPtrArr[1], ptrArr, sizeof(int*) * (ptrArrSize - 1));
//             tempPtrArr[0] = new int[DEQUE_ARR_SIZE];

//             front += DEQUE_ARR_SIZE;
//             back += DEQUE_ARR_SIZE;
            
//             ptrArr = tempPtrArr;
//         }

//         ptrArr[back / ptrArrSize][back % DEQUE_ARR_SIZE] = n;
//         --back;
//     }
//     void PopFront()
//     {
//         if(front == back)
//         {
//             cout << -1 << "\n";
//             return;
//         }

//         cout << ptrArr[front / ptrArrSize][front % DEQUE_ARR_SIZE] << "\n";
//         front -= 1;
//     }
//     void PopBack()
//     {
//         if(front == back)
//         {
//             cout << -1 << "\n";
//             return;
//         }

//         back += 1;
//         cout << ptrArr[back / ptrArrSize][back % DEQUE_ARR_SIZE] << "\n";
//     }
//     void Size()
//     {
//         if(back < 0)
//             cout << front - back + 1 << "\n";
//         else
//             cout << front - back << "\n";

//     }
//     void Empty()
//     {
//         if(front == back)
//             cout << 1 << "\n";
//         else
//             cout << 0 << "\n";
//     }
//     void Front()
//     {
//         if(front == back)
//         {
//             cout << -1 << "\n";
//             return;
//         }

//         cout << ptrArr[front / ptrArrSize][front % DEQUE_ARR_SIZE] << "\n";
//     }
//     void Back()
//     {
//         if(front == back)
//         {
//             cout << -1 << "\n";
//             return;
//         }

//         cout << ptrArr[(back + 1) / ptrArrSize][(back + 1) % DEQUE_ARR_SIZE] << "\n";
//     }

// private:
//     int** ptrArr;
//     int ptrArrSize = 5;

//     int front = 0;
//     int back = 0;
// };

// int main(void)
// {
//     fastIo

//     Deque deque;
//     int n;
//     string commend;
//     cin >> n;

//     for(int i = 0; i < n; ++i)
//     {
//         cin >> commend;
//         deque.Commend(commend);
//     }

//     return 0;
// }