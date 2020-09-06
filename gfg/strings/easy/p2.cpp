// Reverse each word in a given string
// https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string/0

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
        char c[n];
        for (int i = 0; i < n; i++)
            c[i] = s[i];
        string rev="", cur="";
        int cur_num = 0, sum = 0, l = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (c[i] == '.')
            {
                rev="."+cur+rev;
                cur="";
            }
            else
            {
                cur+=c[i];
            }
        }
        rev=cur+rev;
        cout << rev << endl;
    }
    return 0;
}