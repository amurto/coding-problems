// https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0
// Roman Number to Integer

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int value(char c)
{
    if(c == 'I')
        return 1;
    else if(c == 'V')
        return 5;
    else if(c == 'X')
        return 10;
    else if(c == 'L')
        return 50;
    else if(c == 'C')
        return 100;
    else if(c == 'D')
        return 500;
    else if(c == 'M')
        return 1000;
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        int n = s.length();
        int sum = 0;
        for (int i=0; i<n-1; i++) {
            if (value(s[i])>=value(s[i+1]))
                sum+=value(s[i]);
            else
                sum-=value(s[i]);
        }
        sum+=value(s[n-1]);
        cout<<sum<<endl;
    }
    return 0;
}