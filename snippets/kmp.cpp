// KMP String Searching Algorithm

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void computeLPS(string &pat, vector<int> &lps, int m)
{
    lps[0] = 0;
    int len = 0, i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = ++len;
            i++;
        }
        else
        {
            if (len == 0)
                lps[i++] = 0;
            else
                len = lps[len - 1];
        }
    }
}

// Find occurences of "pat" in "text"
int KMPSearch(string &text, string &pat)
{
    int n = text.length(), m = pat.length();
    vector<int> lps(m);
    computeLPS(pat, lps, m);
    int i = 0, j = 0, res = 0;
    while (i < n)
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            j = lps[j - 1];
            res++;
        }
        else if (i < n && text[i] != pat[j])
        {
            if (j > 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    // Count of string s2 in s1
    cout << KMPSearch(s1, s2) << "\n";
    return 0;
}