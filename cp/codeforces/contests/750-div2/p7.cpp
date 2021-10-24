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

const int M = 8192, inf = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), ids(n + 1), dp(M, inf), seq;
    vector<vector<int>> pos(M);

    pos[0].pb(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]].pb(i);
    }

    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return arr[i1] < arr[i2]; });
    dp[0] = 0;
    for (int i = 0; i <= n;)
    {
        vector<int> tdp = dp;
        int r = i, cur = arr[ids[i]];
        while (r <= n && cur == arr[ids[r]])
            r++;
        for (int j = 0; j < M; j++)
        {
            if (dp[j] < pos[cur].back())
            {
                int idx = lower_bound(pos[cur].begin(), pos[cur].end(), dp[j]) - pos[cur].begin();
                tdp[j ^ cur] = min(tdp[j ^ cur], pos[cur][idx]);
            }
        }
        swap(tdp, dp);
        i = r;
    }
    for (int i = 0; i < M; i++)
        if (dp[i] < inf)
            seq.pb(i);
    cout << (int)seq.size() << "\n";
    for (int x : seq)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}