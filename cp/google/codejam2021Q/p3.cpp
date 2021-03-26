#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int idx(vector<pair<int, int>> &op, int cur)
{
    for (int i = op.size() - 1; i >= 0; i--)
    {
        if (cur >= op[i].first && cur <= op[i].second)
        {
            int d = cur - op[i].first;
            cur = op[i].second - d;
        }
    }
    return cur;
}

void solve()
{
    int n, c;
    cin >> n >> c;
    if (c < n - 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> arr(n, n);
    vector<pair<int, int>> op;
    for (int i = 0; i < n - 1; i++)
    {
        int j = n - 1;
        int u = c - (j - (i + 1));
        u = min(j - i + 1, u);
        arr[idx(op, i + u - 1)] = i + 1;
        op.pb({i, i + u - 1});
        c -= u;
    }
    if (c > 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int a : arr)
        cout << a << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}