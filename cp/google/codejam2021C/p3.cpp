#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;
int vis[N];

int bnot(int x)
{
    int y = 0;
    for (int i = 0; x > 0; x >>= 1, i++)
        y |= (((x & 1) ^ 1) << i);
    return y;
}
int solve(int tc)
{
    int s, e, op = 1;
    cin >> s >> e;
    if (s == e)
        return 0;
    queue<int> q;
    q.push(s);
    vis[s] = tc;
    while (op < 100 && !q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            int cur = q.front();
            q.pop();
            if (cur * 2 == e)
                return op;
            if (cur * 2 < N && vis[cur * 2] != tc)
            {
                vis[cur * 2] = tc;
                q.push(cur * 2);
            }
            if (bnot(cur) == e)
                return op;
            if (bnot(cur) < N && vis[bnot(cur)] != tc)
            {
                vis[bnot(cur)] = tc;
                q.push(bnot(cur));
            }
        }
        op++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(vis, 0, sizeof(vis));
    // int n;
    // cin >> n;
    // cout << bnot(n) << "\n";
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        int res = solve(tc);
        res == -1 ? cout << "IMPOSSIBLE\n" : cout << res << "\n";
    }
    return 0;
}