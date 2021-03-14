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

ll solve()
{
    int n;
    ll res = 0;
    string str;
    cin >> n >> str;
    for (int i = 0; i < n; i++)
    {
        string pre = str.substr(0, i + 1);
        res += KMPSearch(str, pre);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}