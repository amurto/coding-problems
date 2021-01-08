#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6;
vector<int> psf(N + 1, 1);

void precompute()
{
    for (int i = 1; i * i <= N; i++)
        for (int j = i * i, k = 1; j <= N; j += i * i, k++)
            psf[j] = k;
}

void solve()
{
    int n, q, res1 = 0, res2 = 0;
    cin >> n;
    vector<ll> arr(n);
    unordered_map<int, int> dp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[psf[arr[i]]]++;
    }
    for (auto x : dp)
    {
        res1 = max(res1, x.second);
        if (x.first == 1 || x.second % 2 == 0)
            res2 += x.second;
    }
    cin >> q;
    while (q-- > 0)
    {
        ll w;
        cin >> w;
        if (w == 0)
            cout << res1 << "\n";
        else
            cout << max(res1, res2) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precompute();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}