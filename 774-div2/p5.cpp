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

const int N = 1e6 + 5;
// O(n)
vector<int> lp(N + 1), pr;
bool is_prime[N];
void sieve()
{
    is_prime[1] = true;
    for (int i = 2; i <= N; i++)
    {
        is_prime[i] = false;
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int p : pr)
        is_prime[p] = true;
}

ll brute_force(int n, int m)
{
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = i + 1;
        for (int j = 1; j < m; j++)
            arr[i][j] = arr[i][j - 1] * 1ll * (i + 1);
    }
    set<ll> st;
    for (int i = 0; i < n; i++)
        for (ll v : arr[i])
            st.insert(v);
    return (int)st.size();
}

ll dfs(vector<int> &nums, ll val, int i, int sz, ll n, ll m, int t)
{
    if (i == sz)
    {
        if (t & 1)
            return -(m / val);
        return (m / val);
    }
    ll res = 0;
    if (val * nums[i] <= m)
        res += dfs(nums, val * nums[i], i + 1, sz, n, m, t + 1);
    res += dfs(nums, val, i + 1, sz, n, m, t);
    return res;
}

ll solve()
{
    ll n, m;
    cin >> n >> m;
    ll res = 1;
    vector<int> nums;
    map<ll, ll> vis;
    for (ll i = 2; i <= n; i++)
        for (ll j = i; j <= n; j *= i)
            vis[j] = i;
    for (int i = 2; i <= n; i++)
    {
        ll cur = i;
        int cnt = 1;
        nums.clear();
        while (cur <= n)
        {
            if (vis[cur] != i && is_prime[cnt])
                nums.pb(cnt);
            cnt++;
            cur *= i;
        }
        int sz = (int)nums.size();
        ll v = dfs(nums, 1ll, 0, sz, n, m, 0);
        cout << i << " -> " << v << "\n";
        res += v;
    }
    d(brute_force(n, m));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    cout << solve() << "\n";
    return 0;
}