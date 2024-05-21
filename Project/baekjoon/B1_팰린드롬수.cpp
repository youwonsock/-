#include <bits/stdc++.h>

using namespace std;
#define fastIo ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(void)
{
    fastIo

    string n = "";
    bool palindrome = true;

    while(true)
    {
        cin >> n;
        if(n=="0") 
            break;
        
        palindrome = true;
        for(int i = 0; i < n.length()/2; ++i)
        {
            if(n[i] != n[n.length() - 1 - i])
            {
                palindrome = false;
                break;
            }
        }

        if(palindrome)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }

    return 0;
}