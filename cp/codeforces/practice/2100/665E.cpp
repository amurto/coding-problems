// https://codeforces.com/contest/665/problem/E
// Beautiful Subarrays

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

// Bit Trie
// set LGN to 60 for long long
const int N = 1e6 + 5, LGN = 30;
int t[N * LGN][2], cnt[N * LGN], mask = 1;

void init()
{
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
}

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
    // keep running sum
    cnt[v]++;
}

ll dfs(int cur, int k, int v, int bit)
{
    if (bit == -1)
        return 1ll * cnt[v];
    int e = ((cur >> bit) & 1), b = ((k >> bit) & 1);
    ll res = 0;
    if (b == 1)
    {
        int r = (e == 1) ? 0 : 1;
        if (t[v][r] > 0)
            res += dfs(cur, k, t[v][r], bit - 1);
    }
    else
    {
        int r = (e == 1) ? 1 : 0;
        res += 1ll * cnt[t[v][r ^ 1]];
        if (t[v][r] > 0)
            res += dfs(cur, k, t[v][r], bit - 1);
    }
    return res;
}

ll solve()
{
    int n, k;
    cin >> n >> k;
    ll res = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    init();
    insert(0, 1, LGN);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur ^= arr[i];
        res += dfs(cur, k, 1, LGN);
        insert(cur, 1, LGN);
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