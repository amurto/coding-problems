// https://codeforces.com/problemset/problem/217/A
// Ice Skating

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void dfs(int cur, vector<pair<int, int>> &points, vector<bool> &vis)
{
    vis[cur] = true;
    for (int i = 0; i < points.size(); i++)
        if (vis[i])
            continue;
        else if (points[cur].first == points[i].first || points[cur].second == points[i].second)
            dfs(i, points, vis);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, y, drifts = 0;
    cin >> n;
    vector<pair<int, int>> points(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        dfs(i, points, vis);
        drifts++;
    }
    cout << drifts - 1 << "\n";
    return 0;
}