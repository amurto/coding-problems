// https://codeforces.com/contest/1010/problem/D
// Mars rover

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;
int g[N][2], bit[N], flip[N];
string op[N];
int calc(int cur)
{
    if (op[cur] == "AND")
        return bit[g[cur][0]] & bit[g[cur][1]];
    else if (op[cur] == "OR")
        return bit[g[cur][0]] | bit[g[cur][1]];
    else if (op[cur] == "XOR")
        return bit[g[cur][0]] ^ bit[g[cur][1]];
    return bit[g[cur][0]] ^ 1;
}

void dfs(int cur)
{
    if (op[cur] != "IN")
    {
        for (int e : g[cur])
            if (e != 0)
                dfs(e);
        bit[cur] = calc(cur);
    }
}

void traverse(int cur)
{
    if (flip[cur] == 1)
    {
        string tmp = op[cur];
        int l = g[cur][0], r = g[cur][1], c = bit[cur] ^ 1;
        if (tmp == "AND")
        {
            if (c == ((bit[l] ^ 1) & bit[r]))
                flip[l] = 1;
            if (c == (bit[l] & (bit[r] ^ 1)))
                flip[r] = 1;
        }
        else if (tmp == "OR")
        {
            if (c == ((bit[l] ^ 1) | bit[r]))
                flip[l] = 1;
            if (c == (bit[l] | (bit[r] ^ 1)))
                flip[r] = 1;
        }
        else if (tmp == "XOR")
        {
            if (c == ((bit[l] ^ 1) ^ bit[r]))
                flip[l] = 1;
            if (c == (bit[l] ^ (bit[r] ^ 1)))
                flip[r] = 1;
        }
        else if (tmp == "NOT")
        {
            if (c == bit[l])
                flip[l] = 1;
        }
    }
    for (int e : g[cur])
        if (e > 0)
            traverse(e);
}

void solve()
{
    int n;
    string tmp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i][0] = g[i][1] = 0;
        cin >> op[i];
        if (op[i] == "IN")
            cin >> bit[i];
        else
        {
            cin >> g[i][0];
            if (op[i] != "NOT")
                cin >> g[i][1];
        }
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        flip[i] = 0;
    flip[1] = 1;
    traverse(1);
    for (int i = 1; i <= n; i++)
        if (op[i] == "IN")
            cout << (bit[1] ^ flip[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}