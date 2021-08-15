#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 1e5 + 5;
int two[N], sub[N], cnt[N];
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

int solve()
{
    int n, dep, res = 0;
    cin >> n >> dep;
    vector<int> arr(n), pos;
    map<int, int> cnt, inv, dp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > dep)
            pos.pb(arr[i]);
        cnt[arr[i]]++;
    }
    int sum = 0;
    for (int i = -dep; i <= dep; i++)
        sum += cnt[i];
    res = add(res, add(sub[sum], -sum));
    res = add(res, mul(sub[sum], n - sum));
    int k = 2 * dep + 1;
    vector<int> st(k);

    for (int i = 0, j = -dep; i < k; i++, j++)
    {
        inv[j] = i;
        st[i] = j;
    }
    for (int i = 1; i < (1 << k); i++)
    {
        int w = 1;
        set<int> seq;
        for (int j = 0; j < k; j++)
            if ((i >> j) & 1)
                seq.insert(st[j]);
        int sz = seq.size();
        bool c = true;
        for (int j : seq)
            w = mul(w, sub[cnt[j]]);
        for (int j = -dep; j <= dep; j++)
        {
            bool sat = false;
            for (int k = -dep; k <= dep; k++)
                if (seq.count(max(-dep, min(dep, j + k))))
                    sat = true;
            if (sat)
                dp[j] = add(dp[j], w);
        }
    }
    // for (int j=-dep; j<=dep; j++)   
    //     d(j,dp[j]);
    for (int p : pos)
    {
        for (int j = -dep; j <= dep; j++)
        {
            int v = -(p + j);
            if (abs(v) > dep && cnt[v] > 0)
            {
                int diff = p + v;
                res = add(res, mul(mul(cnt[p], cnt[v]), dp[diff]));
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    two[0] = 1;
    sub[0] = 0;
    for (int i = 1; i < N; i++)
    {
        two[i] = mul(two[i - 1], 2);
        sub[i] = add(two[i], -1);
    }
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}