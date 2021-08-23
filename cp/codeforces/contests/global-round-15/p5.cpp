#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n * k + 1), wt(n * k + 1);
    vector<vector<int>> cols(n + 1);
    vector<pii> ivs, seq(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n * k; i++)
    {
        cin >> arr[i];
        cols[arr[i]].pb(i);
    }
    int req = (n + k - 2) / (k - 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < k; j++)
            ivs.pb({cols[i][j - 1], cols[i][j]});
    sort(ivs.begin(), ivs.end(), [&](pii &i1, pii &i2)
         { return i1.second < i2.second; });
    for (pii i : ivs)
    {
        if (!vis[arr[i.first]])
        {
            int wmx = 0;
            for (int j = i.first; j <= i.second; j++)
                wmx = max(wmx, wt[j]);
            if (wmx < req)
            {
                for (int j = i.first; j <= i.second; j++)
                    wt[j]++;
                vis[arr[i.first]] = true;
                seq[arr[i.first]] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << seq[i].first << " " << seq[i].second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}