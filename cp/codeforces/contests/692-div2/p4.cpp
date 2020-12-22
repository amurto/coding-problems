#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll op(string &str, int start, int q, ll x, ll y)
{
    int zero = 0, one = 0, L = start, R = start ^ 1;
    ll res = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int use = 0;
        if (str[i] == '?')
            use = (q-- > 0) ? L : R;
        else
            use = str[i] - '0';
        if (use == 0)
        {
            res += (one * y);
            zero++;
        }
        else
        {
            res += (zero * x);
            one++;
        }
    }
    return res;
}

ll solve()
{
    string str;
    cin >> str;
    int n = str.length(), q = count(str.begin(), str.end(), '?');
    ll x, y, res = 1e17;
    cin >> x >> y;
    if (q == 0)
        return op(str, 0, 0, x, y);
        
    // ternary search
    int l, r;
    l = 0, r = q - 1;
    while (l <= r)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        ll r1 = op(str, 0, m1, x, y), r2 = op(str, 0, m2, x, y);
        res = min({res, r1, r2});
        if (r1 < r2)
            r = m2 - 1;
        else
            l = m1 + 1;
    }
    l = 0, r = q - 1;
    while (l <= r)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        ll r1 = op(str, 1, m1, x, y), r2 = op(str, 1, m2, x, y);
        res = min({res, r1, r2});
        if (r1 < r2)
            r = m2 - 1;
        else
            l = m1 + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}