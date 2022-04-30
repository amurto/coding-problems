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

const int MX = 1e9;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> arr;
    vector<set<int>> vis1(3);
    set<int> vis2;
    for (int i = 1; i <= max(n + 3 * m, 3 * n + m); i++)
    {
        vis1[i % 3].insert(i);
        vis2.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int p = i % 3;
        while (!vis1[p].empty() && *vis1[p].begin() < i + 3)
            vis1[p].erase(vis1[p].begin());
        vector<int> del;
        for (int x : vis1[p])
        {
            int j = (x - i) / 3;
            if (j <= 0 || j > m)
                break;
            if (vis2.count(3 * i + j))
            {
                del.pb(i + 3 * j);
                arr.pb({i, j});
                vis2.erase(3 * i + j);
            }
        }
        for (int dd : del)
            vis1[p].erase(dd);
    }
    cout << (int)arr.size() << "\n";
    for (pii p : arr)
        cout << p.first << " " << p.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}