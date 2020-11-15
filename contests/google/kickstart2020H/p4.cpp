#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int bfs(vector<vector<int>> &g, int a, int b)
{
    if (a == b)
        return 0;
    int chain = 1;
    queue<int> que;
    vector<bool> vis(g.size());
    que.push(a);
    while (!que.empty())
    {
        int len = que.size();
        while (len-- > 0)
        {
            int cur = que.front();
            que.pop();
            if (cur == b)
                return chain;
            if (vis[cur])
                continue;
            vis[cur] = true;
            for (int adj : g[cur])
            {
                if (vis[adj])
                    continue;
                que.push(adj);
            }
        }
        chain++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int ti = 1; ti <= t; ti++)
    {
        int n, q;
        string s;
        cin >> n >> q;
        vector<vector<int>> MAP(26);
        vector<string> S(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> S[i];
            unordered_set<char> SET(S[i].begin(), S[i].end());
            for (char x : SET)
                MAP[x - 'A'].pb(i);
        }
        vector<vector<int>> g(n + 1);
        for (int i = 1; i <= n; i++)
        {
            unordered_set<int> SET;
            for (char ch : S[i])
                for (int adj : MAP[ch - 'A'])
                    SET.insert(adj);
            for (int x : SET)
                g[i].pb(x);
        }
        map<pair<int, int>, int> store;
        cout << "Case #" << ti << ": ";
        while (q-- > 0)
        {
            int a, b;
            cin >> a >> b;
            if (store[{a, b}] == 0 && store[{b, a}] == 0)
            {
                store[{a, b}] = bfs(g, a, b);
                store[{b, a}] = store[{a, b}];
            }
            cout << store[{a, b}] << " ";
        }
        cout << "\n";
    }
    return 0;
}