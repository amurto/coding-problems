// https://codeforces.com/contest/552/problem/E
// Vanya and Brackets

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll op(ll x1, ll x2, char ch)
{
    if (ch == '+')
        return x1 + x2;
    return x1 * x2;
}

ll solve()
{
    string str;
    cin >> str;
    vector<int> digs;
    vector<char> ops;
    for (char ch : str)
        if (ch >= '0' && ch <= '9')
            digs.pb(ch - '0');
        else
            ops.pb(ch);
    int n = digs.size();

    vector<vector<ll>> st(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        ll sum = 0, p = 1ll * digs[i];
        st[i][i] = p;
        for (int j = i + 1; j < n; j++)
        {
            if (ops[j - 1] == '+')
            {
                sum += p;
                p = 1ll * digs[j];
            }
            else
                p *= digs[j];
            st[i][j] = sum + p;
        }
    }
    ll mx = st[0][n - 1];
    ll x_p = 1ll * digs[0], x_sum = 0;
    for (int l = 0; l < n - 1; l++)
    {
        if (l > 0)
        {
            if (ops[l - 1] == '+')
            {
                x_sum += x_p;
                x_p = 1ll * digs[l];
            }
            else
                x_p *= digs[l];
        }
        mx = max(mx, x_sum + op(x_p, st[l + 1][n - 1], ops[l]));
    }
    ll r_sum = 0, r_p = 1ll * digs[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        if (i < n - 1)
        {
            if (ops[i] == '+')
            {
                r_sum += r_p;
                r_p = digs[i];
            }
            else
                r_p *= digs[i];
        }
        char ch2 = ops[i - 1];
        mx = max(mx, op(st[0][i - 1], r_p, ch2) + r_sum);
        ll l_p = 1ll * digs[0], l_sum = 0;
        for (int j = 1; j < i; j++)
        {
            char ch1 = ops[j - 1];
            ll v = st[j][i - 1];
            if (ch1 == '*')
                mx = max(mx, l_sum + op(op(l_p, v, ch1), r_p, ch2) + r_sum);
            else
                mx = max(mx, l_sum + op(l_p, op(r_p, v, ch2), ch1) + r_sum);
            if (ch1 == '+')
            {
                l_sum += l_p;
                l_p = digs[j];
            }
            else
                l_p *= digs[j];
        }
    }
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}