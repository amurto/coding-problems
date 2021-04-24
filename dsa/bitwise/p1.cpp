// https://csacademy.com/contest/round-42/task/xor-submatrix/
// Xor Submatrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Bit Trie
const int N = 1e6 + 1, LGN = 30;
int t[N * LGN][2], cnt[N * LGN], mask = 1;

void insert(int x, int v, int bit)
{
    if (bit == -1)
    {
        cnt[v]++;
        return;
    }
    int child = (x >> bit) & 1;
    if (t[v][child] == 0)
        t[v][child] = ++mask;
    insert(x, t[v][child], bit - 1);
}

int query(int x, int v, int bit)
{
    if (bit == -1)
        return 0;
    int child = (x >> bit) & 1;
    if (t[v][child ^ 1] > 0)
        return (1 << bit) | query(x, t[v][child ^ 1], bit - 1);
    return query(x, t[v][child], bit - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> v(n), u(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> u[i];
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = i, p = 1; j < n; j++, p ^= 1)
        {
            x ^= v[j];
            if (p & 1)
                insert(x, 1, LGN);
            else
                res = max(res, x);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x = 0;
        for (int j = i, p = 1; j < m; j++, p ^= 1)
        {
            x ^= u[j];
            if (p & 1)
                res = max(res, query(x, 1, LGN));
            else
                res = max(res, x);
        }
    }
    cout << res << "\n";
    return 0;
}