#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 25;
const ll MOD = 1e9 + 7;
ll seq[N];

ll add(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    x %= MOD;
    y %= MOD;
    return (x * 1ll * y) % MOD;
}

void init()
{
    vector<ll> cnt(10);
    cnt[0] = seq[0] = 1;
    for (int i = 1; i < N; i++)
    {
        seq[i] = 0;
        vector<ll> tmp(10);
        for (int j = 0; j < 9; j++)
            tmp[j + 1] = cnt[j];
        tmp[0] = add(tmp[0], cnt[9]);
        tmp[1] = add(tmp[1], cnt[9]);
        cnt = tmp;
        for (int j = 0; j < 10; j++)
            seq[i] = add(seq[i], cnt[j]);
    }
}

ll solve()
{
    int n, m;
    cin >> n >> m;
    ll res = 0;
    while (n > 0)
    {
        int d = n % 10;
        res = add(res, seq[d + m]);
        n /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}