#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e9 + 7;
bool is_palindrome(string &str)
{
    int len = str.length();
    for (int i = 0, j = len - 1; i <= j; i++, j--)
        if (str[i] != str[j])
            return false;
    return true;
}

int solve()
{
    int n, res = inf;
    string str;
    cin >> n >> str;
    for (int k = 0; k < 26; k++)
    {
        int cnt = 0, op = 0;
        string tmp = "";
        for (char ch : str)
            if (ch - 'a' == k)
                cnt++;
            else
                tmp.pb(ch);
        if (cnt == n)
            return 0;
        if (is_palindrome(tmp))
        {
            vector<int> seq;
            if (str[0] - 'a' != k)
                seq.pb(0);
            for (int i = 0; i < n;)
            {
                if (str[i] - 'a' != k)
                {
                    if (i + 1 < n && str[i + 1] - 'a' != k)
                        seq.pb(0);
                    i++;
                }
                else
                {
                    int r = i;
                    while (r < n && str[r] - 'a' == k)
                        r++;
                    seq.pb(r - i);
                    i = r;
                }
            }
            if (str.back() - 'a' != k)
                seq.pb(0);
            int sz = seq.size();
            for (int i = 0, j = sz - 1; i <= j; i++, j--)
                if (i == j)
                    op += seq[i];
                else
                    op += (2 * min(seq[i], seq[j]));
            res = min(res, cnt - op);
        }
    }
    return res >= inf ? -1 : res;
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