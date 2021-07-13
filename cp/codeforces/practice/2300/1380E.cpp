// https://codeforces.com/contest/1380/problem/E
// Merging Towers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
int arr[N], mask[N], unmask[N], sz[N];
set<int> st[N];
int op = 0;

void merge(int a, int b)
{
    int u = unmask[a], v = unmask[b];
    if (sz[u] < sz[v])
        swap(u, v);
    vector<int> tmp(st[v].begin(), st[v].end());
    int len = tmp.size(), prev = 0;
    for (int i = 0; i < len; i++)
    {
        int pos = tmp[i];
        if (prev != pos - 1)
            op -= (arr[pos - 1] == u);
        op -= (i < len && tmp[i + 1] != pos + 1 && arr[pos + 1] == u);
        prev = pos;
    }
    for (int x : tmp)
    {
        arr[x] = u;
        st[u].insert(x);
    }
    sz[u] += sz[v];
    mask[u] = mask[v] = a;
    unmask[a] = u;
}

void solve()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        mask[i] = unmask[i] = i;
        sz[i] = 1;
    }
    for (int i = 2; i <= n; i++)
        op += (arr[i - 1] != arr[i]);
    for (int i = 1; i <= n; i++)
        st[arr[i]].insert(i);
    cout << op << "\n";
    for (int i = 0; i < m - 1; i++)
    {
        cin >> a >> b;
        merge(a, b);
        cout << op << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}