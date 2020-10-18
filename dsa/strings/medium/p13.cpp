#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// O(n)
string isFormableBySubstring(string s)
{
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
            {
                len = LPS[len - 1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
    if (len > 0 && n % (n - len) == 0)
        return "True";
    else
        return "False";
}

// O(n^2)
string repeatedSubstringPattern(string s)
{
    int n = s.length();
    if (n == 1)
        return "False";
    char c[n];
    for (int i = 0; i < n; i++)
        c[i] = s[i];
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0 && c[i] == c[0])
        {
            bool ans = true;
            for (int j = 0; j < i; j++)
            {
                int idx = i + j;
                while (idx < n && c[idx] == c[j])
                    idx += i;
                if (idx < n)
                {
                    ans = false;
                    break;
                }
            }
            if (ans)
                return "True";
        }
    }
    return "False";
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        cout << isFormableBySubstring(s) << endl;
    }
    return 0;
}