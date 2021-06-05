#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int m, res = 0;
    cin >> m;
    string a, b;
    vector<string> arr, from, to;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (a != b)
        {
            arr.pb(a);
            arr.pb(b);
            from.pb(a);
            to.pb(b);
        }
    }
    if (arr.empty())
        return res;
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    int sz = arr.size();
    vector<int> prev(sz, -1), nxt(sz, -1);
    vector<bool> vis(sz);
    for (int i = 0; i < from.size(); i++)
    {
        int id1 = lower_bound(arr.begin(), arr.end(), from[i]) - arr.begin();
        int id2 = lower_bound(arr.begin(), arr.end(), to[i]) - arr.begin();
        nxt[id1] = id2;
        prev[id2] = id1;
    }
    for (int i = 0; i < sz; i++)
    {
        if (!vis[i] && prev[i] == -1)
        {
            vis[i] = true;
            int cur = nxt[i], len = 1;
            while (cur != -1)
            {
                vis[cur] = true;
                cur = nxt[cur];
                len++;
            }
            len--;
            res += len;
        }
    }
    for (int i = 0; i < sz; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            int cur = nxt[i], len = 1;
            while (cur != i)
            {
                vis[cur] = true;
                cur = nxt[cur];
                len++;
            }
            len++;
            res += len;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}