// https://codeforces.com/contest/1097/problem/D
// Makoto and a Blackboard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

map<ll, int> primes, divs;
vector<ll> st;
int pre[15][55];

int dfs(int cur, ll d, int p)
{
    if (cur == st.size())
        return mul(d % MOD, p);
    ll tmp = d;
    int mx = primes[st[cur]], res = 0;
    for (int i = 0; i <= mx; i++, tmp *= st[cur])
        res = add(res, dfs(cur + 1, tmp, mul(p, pre[cur][i])));
    return res;
}

int solve()
{
    ll n;
    int k;
    cin >> n >> k;
    ll x = n;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            st.pb(i);
            ll cnt = 0;
            while (x % i == 0)
            {
                x /= i;
                cnt++;
            }
            primes[i] = cnt;
        }
    }
    if (x > 1)
    {
        st.pb(x);
        primes[x] = 1;
    }
    for (int i = 0; i < st.size(); i++)
    {
        int cnt = primes[st[i]];
        vector<vector<int>> dp(k + 1, vector<int>(cnt + 2));
        dp[0][cnt] = 1;
        for (int j = 1; j <= k; j++)
            for (int c = cnt; c >= 0; c--)
                dp[j][c] = add(mul(power(c + 1, MOD - 2, MOD), dp[j - 1][c]), dp[j][c + 1]);
        for (int j = 0; j <= cnt; j++)
            pre[i][j] = dp[k][j];
    }
    return dfs(0, 1, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}