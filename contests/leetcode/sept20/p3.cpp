// Repeated Substring Pattern
// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3447/

#include <bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s)
{
    int n= s.length();
    if (n==1)
        return false;
    char c[n];
    for (int i=0;i < n; i++)
        c[i] = s[i];
    for (int i=1;i<=n/2; i++) {
        if (n%i==0 && c[i]==c[0]) {
            bool ans = true;
            for (int j=0; j<i;j++) {
                int idx=i+j;
                while (idx<n && c[idx] == c[j])
                    idx+=i;
                if (idx<n) {
                    ans=false;
                    break;
                }
            }
            if (ans)
                return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin>>s;
        cout<<repeatedSubstringPattern(s);
    }
    return 0;
}