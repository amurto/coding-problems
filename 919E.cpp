// https://codeforces.com/contest/919/problem/E
// Congruence Equation

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int mul(int x, int y, int MOD)
{
    return (x * 1ll * y) % MOD;
}

ll solve()
{
    int a, b, p;
    ll x, res = 0;
    cin >> a >> b >> p >> x;
    vector<int> seq(p + 1);
    seq[0] = 1;
    for (int i = 1; i <= p; i++)
        seq[i] = mul(seq[i - 1], a, p);
    for (int i = 1; i <= x && i < p; i++)
        if (mul(i, seq[i], p) == b)
        {
            // cout << i << "\n";
            res++;
            ll k = ((x - i) / (p + 1));
            res += k;
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