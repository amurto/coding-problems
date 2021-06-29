// https://codeforces.com/contest/844/problem/B
// Rectangles

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, m;
    ll res = 0;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
    {
        vector<int> cnt(2);
        for (int j = 0; j < m; j++)
            cnt[arr[i][j]]++;
        res += (1ll << cnt[0]) + (1ll << cnt[1]) - 2;
    }
    for (int j = 0; j < m; j++)
    {
        vector<int> cnt(2);
        for (int i = 0; i < n; i++)
            cnt[arr[i][j]]++;
        res += (1ll << cnt[0]) + (1ll << cnt[1]) - 2;
    }
    return res - n * 1ll * m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}