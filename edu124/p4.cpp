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
    int n, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    cin >> n;
    vector<int> X(n + 1), Y(n + 1);
    vector<bool> vis(n + 1);
    vector<pii> pts(n + 1);
    map<ll, int> ids;
    auto get_hash = [](int x, int y)
    {
        return ((x * 1ll) << 30ll) + y;
    };
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i] >> Y[i];
        ids[get_hash(X[i], Y[i])] = i;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (int dir = 0; !vis[i] && dir < 4; dir++)
        {
            int tx = X[i] + dx[dir], ty = Y[i] + dy[dir];
            if (ids[get_hash(tx, ty)] == 0)
            {
                vis[i] = true;
                pts[i] = {tx, ty};
                q.push(i);
            }
        }
    }
    while (!q.empty())
    {
        int sz = (int)q.size();
        while (sz > 0)
        {
            int cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int tx = X[cur] + dx[dir], ty = Y[cur] + dy[dir];
                int idx = ids[get_hash(tx, ty)];
                if (idx != 0 && !vis[idx])
                {
                    vis[idx] = true;
                    pts[idx] = pts[cur];
                    q.push(idx);
                }
            }
            sz--;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << pts[i].first << " " << pts[i].second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}