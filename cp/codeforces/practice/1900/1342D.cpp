// https://codeforces.com/contest/1342/problem/D
// Multiple Testcases

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, k;
    cin >> n >> k;
    vector<int> arr(n), freq(k + 1), c(k + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for (int i = 1; i <= k; i++)
        cin >> c[i];
    ll mx = 1, pre = 0;
    for (int i = k; i > 0; i--)
    {
        if (freq[i] == 0)
            continue;
        pre += freq[i];
        mx = max(mx, (pre + c[i] - 1) / c[i]);
    }
    vector<vector<int>> g(mx);
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
        g[i % mx].pb(arr[i]);
    cout << mx << "\n";
    for (int i = 0; i < mx; i++)
    {
        cout << g[i].size() << " ";
        for (int x : g[i])
            cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}