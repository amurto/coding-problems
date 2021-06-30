// https://codeforces.com/contest/204/problem/C
// Little Elephant and Furik and Rubik

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int K = 26;

double resolve(ll v, ll den)
{
    return (1.0 * v) / (1.0 * den);
}

double solve()
{
    int n;
    string strA, strB;
    cin >> n >> strA >> strB;
    ll num = 0, den = 0;
    for (int i = 1; i <= n; i++)
        den += 1ll * (n - i + 1) * (n - i + 1);
    vector<vector<ll>> pre(n, vector<ll>(K)), suf(n, vector<ll>(K));
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            pre[i] = pre[i - 1];
        pre[i][strA[i] - 'A'] += 1ll * (i + 1);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i != n - 1)
            suf[i] = suf[i + 1];
        suf[i][strA[i] - 'A'] += 1ll * (n - i);
    }
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        if (strA[i] == strB[i])
        {
            ll l = 1ll * (i + 1), r = 1ll * (n - i);
            res -= resolve(l * r, den);
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll l = 1ll * (i + 1), r = 1ll * (n - i);
        res += resolve(pre[i][strB[i] - 'A'] * r, den);
        res += resolve(suf[i][strB[i] - 'A'] * l, den);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}