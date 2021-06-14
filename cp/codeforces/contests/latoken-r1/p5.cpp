#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(vector<int> arr)
{
    cout << "? ";
    for (int a : arr)
        cout << a << " ";
    cout << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

int solve()
{
    int n, k, d = 1, res = 0;
    cin >> n >> k;
    vector<bool> vis(n + 1);
    vector<int> dis(n + 1), last(n + 1), op(n + 1);
    vis[n] = true;
    dis[n] = 0;
    last[n] = -1;
    queue<int> q;
    q.push(n);
    while (!q.empty() && !vis[0] && d <= 500)
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            int cur = q.front();
            q.pop();
            int e = cur, o = n - cur;
            for (int p = 0; p <= k; p++)
            {
                if (p <= e && k - p <= o)
                {
                    int st = e - p + k - p;
                    if (!vis[st])
                    {
                        vis[st] = true;
                        dis[st] = d;
                        last[st] = cur;
                        op[st] = p;
                        q.push(st);
                    }
                }
            }
        }
        d++;
    }
    if (!vis[0])
        return -1;
    vector<int> seq;
    int cur = 0;
    while (cur != n)
    {
        seq.pb(op[cur]);
        cur = last[cur];
    }
    reverse(seq.begin(), seq.end());
    vector<int> u(n + 1);
    for (int v : seq)
    {
        int e = v, o = k - v;
        vector<int> ids;
        for (int j = 1; (e > 0 || o > 0) && j <= n; j++)
        {
            if (u[j] % 2 == 1)
            {
                if (o > 0)
                {
                    ids.pb(j);
                    u[j] ^= 1;
                    o--;
                }
            }
            else
            {
                if (e > 0)
                {
                    ids.pb(j);
                    u[j] ^= 1;
                    e--;
                }
            }
        }
        res ^= query(ids);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = solve();
    if (ans != -1)
        cout << "! ";
    cout << ans << endl;
    return 0;
}