#include <bits/stdc++.h>

using namespace std;

bool isPrime(int num)
{
    if(num < 2)
        return false;
    
    for(int i = 2; i <= sqrt(num); ++i)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) 
{
    int answer = 0;
    vector<char> numArr;
    set<int> primes;

    for(int i = 0; i < numbers.size(); ++i)
        numArr.push_back(numbers[i]);
    sort(numArr.begin(), numArr.end());

    do {
        string temp = "";

        for (int i = 0; i < numArr.size(); i++) {
            temp.push_back(numArr[i]);
            primes.insert(stoi(temp));
        }
    } while (next_permutation(numArr.begin(), numArr.end()));

    for(auto n : primes)
    {
        if(isPrime(n))
            ++answer;
    }

    return answer;
}