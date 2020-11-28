#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int bfs(vector<vector<int>> &g, vector<string> &S, int a, int b)
{
    unordered_set<int> target(S[b].begin(), S[b].end());
    vector<bool> vis(26);
    queue<int> que;
    for (char ch : S[a])
        que.push(ch - 'A');
    int dis = 0;
    while (!que.empty())
    {
        int len = que.size();
        while (len-- > 0)
        {
            int cur = que.front();
            que.pop();
            if (target.count(cur + 'A'))
                return dis + 2;
            if (vis[cur])
                continue;
            vis[cur] = true;
            for (int j = 0; j < 26; j++)
            {
                if (g[cur][j] == 0 || vis[j])
                    continue;
                que.push(j);
            }
        }
        dis++;
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
        cin >> n >> q;
        vector<vector<int>> g(26, vector<int>(26));
        vector<string> S(n + 1);

        // create an adjacency matrix from the strings
        for (int i = 1; i <= n; i++)
        {
            cin >> S[i];
            for (char c1 : S[i])
                for (char c2 : S[i])
                    g[c1 - 'A'][c2 - 'A'] = g[c2 - 'A'][c1 - 'A'] = 1;
        }
        cout << "Case #" << ti << ": ";
        while (q-- > 0)
        {
            int a, b;
            cin >> a >> b;
            cout << bfs(g, S, a, b) << " ";
        }
        cout << "\n";
    }
    return 0;
}