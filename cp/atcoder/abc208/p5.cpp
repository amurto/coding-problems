#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MX = 1e9 + 5;
vector<ll> st, nums;
ll pw[10][19], dp[20][2][2][2][5200];

void traverse(int cur, ll v)
{
    if (cur == 10)
    {
        st.pb(v);
        return;
    }
    for (int i = 0; i <= 18 && pw[cur][i] <= MX; i++)
    {
        if (v * pw[cur][i] > MX)
            break;
        traverse(cur + 1, v * pw[cur][i]);
    }
}

void init()
{
    for (ll i = 2; i <= 9; i++)
    {
        pw[i][0] = 1;
        for (int j = 1; j <= 18; j++)
            pw[i][j] = pw[i][j - 1] * i;
    }
    traverse(2, 1);
    st.pb(0);
    st.pb(MX);
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
}

ll dfs(int cur, int f, int b, int e, ll p, ll k)
{
    if (cur == nums.size())
        return (e == 0);
    int id = lower_bound(st.begin(), st.end(), p) - st.begin();
    if (dp[cur][f][b][e][id] == -1)
    {
        ll res = 0;
        int lim = 9;
        if (f == 1)
            lim = nums[cur];
        for (int i = 0; i <= lim; i++)
        {
            int tb = (b == 1 && i == 0), tf = (f == 1 && i == lim), te = e;
            ll tp = p * 1ll * i;
            if (tb)
                tp = 1;
            if (tp > k)
            {
                te = 1;
                tp = MX;
            }
            else
                te = 0;
            res += dfs(cur + 1, tf, tb, te, tp, k);
        }
        dp[cur][f][b][e][id] = res;
    }
    return dp[cur][f][b][e][id];
}

ll calc(ll x, ll k)
{
    memset(dp, -1, sizeof(dp));
    nums.clear();
    while (x > 0)
    {
        nums.pb(x % 10);
        x /= 10;
    }
    reverse(nums.begin(), nums.end());
    return dfs(0, 1, 1, 0, 1, k) - 1;
}

ll solve()
{
    ll n, k, res = 0;
    cin >> n >> k;
    return calc(n, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}