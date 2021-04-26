// https://codeforces.com/contest/456/problem/D
// A Lot of Games

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5, K = 26;
int t[N][K], cnt[N], mask = 1;

void insert(string &str)
{
    int cur = 1, i = 0;
    while (i < str.length())
    {
        if (t[cur][str[i] - 'a'] == 0)
            t[cur][str[i] - 'a'] = ++mask;
        cur = t[cur][str[i] - 'a'];
        i++;
    }
    cnt[cur]++;
}

int dfs1(int cur)
{
    int w = 0;
    for (int i = 0; i < K; i++)
        if (t[cur][i] > 0)
            w |= dfs1(t[cur][i]);
    return w ^ 1;
}

int dfs2(int cur)
{
    vector<int> p(2);
    for (int i = 0; i < K; i++)
        if (t[cur][i] > 0)
            p[dfs2(t[cur][i])]++;
    if (p[0] + p[1] == 0)
        return 1;
    return p[0] > 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
    int n, k;
    string str;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        insert(str);
    }
    int w = dfs1(1) ^ 1, l = dfs2(1);
    if (w + l == 2)
        cout << "First\n";
    else if (w > 0)
        k % 2 == 1 ? cout << "First\n" : cout << "Second\n";
    else
        cout << "Second\n";
    return 0;
}