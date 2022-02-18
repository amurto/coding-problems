// https://codeforces.com/contest/1244/problem/F
// Chips

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e9 + 7;

char flipBW(char ch)
{
    if (ch == 'W')
        return 'B';
    return 'W';
}

string solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    string res = str;
    vector<int> vis(n, inf);
    string col(n, '0');
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int prev = (i - 1 + n) % n, nxt = (i + 1) % n;
        if (str[prev] == str[i] || str[i] == str[nxt])
        {
            vis[i] = 0;
            col[i] = str[i];
            q.push(i);
        }
    }
    int t = 1;
    while (!q.empty())
    {
        int sz = (int)q.size();
        while (sz > 0)
        {
            int cur = q.front();
            q.pop();
            array<int, 2> adj{(cur - 1 + n) % n, (cur + 1) % n};
            for (int adj_id : adj)
            {
                if (vis[adj_id] == inf)
                {
                    char ch = str[adj_id];
                    if (t % 2 == 0)
                        ch = flipBW(ch);
                    if (ch == col[cur])
                    {
                        vis[adj_id] = t;
                        col[adj_id] = ch;
                        q.push(adj_id);
                    }
                    else
                        q.push(cur);
                }
            }
            sz--;
        }
        t++;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] <= k)
            res[i] = col[i];
        else
        {
            if (k & 1)
                res[i] = flipBW(res[i]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}