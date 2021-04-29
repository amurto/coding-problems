// https://codeforces.com/contest/1248/problem/D1
// The World Is Just a Programming Task (Easy Version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int mask(char ch)
{
    return (ch == '(') ? 1 : -1;
}

int cycle(string &str, int n)
{
    int res = 0, cur = 0, mn = 2;
    string tmp = str;
    for (char ch : str)
        tmp.pb(ch);
    vector<int> arr(2 * n);
    for (int i = 0; i < n; i++)
    {
        cur += mask(tmp[i]);
        mn = min(mn, cur);
    }
    res += (mn >= 0);
    for (int i = n; i < 2 * n - 1; i++)
    {
        cur -= mask(tmp[i - n]);
        mn -= mask(tmp[i - n]);
        cur += mask(tmp[i]);
        mn = min(mn, cur);
        res += (mn >= 0);
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (count(str.begin(), str.end(), '(') != count(str.begin(), str.end(), ')'))
    {
        cout << "0\n";
        cout << "1 1\n";
        return;
    }
    int l = 0, r = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(str[i], str[j]);
            int val = cycle(str, n);
            if (val >= res)
            {
                res = val;
                l = i;
                r = j;
            }
            swap(str[i], str[j]);
        }
    }
    cout << res << "\n";
    cout << l + 1 << " " << r + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}