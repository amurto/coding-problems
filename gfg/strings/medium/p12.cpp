// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0
// Longest Prefix Suffix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        int n = s.length();
        int LPS[n], len = 0, i = 1;
        LPS[0] = 0;
        while (i < n)
        {
            if (s[i] == s[len])
            {
                LPS[i] = ++len;
                i++;
            }
            else
            {
                if (len > 0)
                    len = LPS[len - 1];
                else
                {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        cout << LPS[n - 1] << endl;
    }
    return 0;
}