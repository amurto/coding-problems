// https://codeforces.com/contest/979/problem/D
// Kuro and GCD and XOR and SUM

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

const int N = 1e5 + 5;
vector<int> divs[N];
bool vis[N];
struct bit_trie
{
    // set LGN to 60 for long long
    static constexpr int LGN = 20;
    static constexpr int ROOT = 0;
    static constexpr int MX = 1e9;
    struct Node
    {
        array<int, 2> ch{-1, -1};
        int cnt = 0, mn = MX;
    };
    int sz;
    vector<Node> t;
    bit_trie()
    {
        sz = 0;
        t.assign(1, Node());
    }
    void insert(int x, int v = ROOT, int bit = LGN)
    {
        if (bit == -1)
        {
            t[v].cnt++;
            t[v].mn = x;
            return;
        }
        int child = (x >> bit) & 1;
        if (t[v].ch[child] == -1)
        {
            t[v].ch[child] = ++sz;
            t.pb(Node());
        }
        insert(x, t[v].ch[child], bit - 1);
        t[v].mn = min(t[v].mn, t[t[v].ch[child]].mn);
        // keep running sum
        t[v].cnt++;
    }

    // max xor with x
    int max_xor_query(int x, int ub, int v = ROOT, int bit = LGN)
    {
        if (bit == -1)
            return 0;
        int child = (x >> bit) & 1;
        if (t[v].ch[child ^ 1] != -1 && t[t[v].ch[child ^ 1]].mn <= ub)
            return (1 << bit) | max_xor_query(x, ub, t[v].ch[child ^ 1], bit - 1);
        if (t[v].ch[child] != -1 && t[t[v].ch[child]].mn <= ub)
            return max_xor_query(x, ub, t[v].ch[child], bit - 1);
        return 0;
    }

    void display(int x = 0, int v = ROOT, int bit = LGN)
    {
        if (bit == -1)
        {
            cout << x << " ";
            return;
        }
        for (int j = 0; j <= 1; j++)
            if (t[v].ch[j] >= 0)
                display(x | (j << bit), t[v].ch[j], bit - 1);
    }
};

void solve()
{

    for (int i = 1; i < N; i++)
    {
        vis[i] = false;
        for (int j = i; j < N; j += i)
            divs[j].pb(i);
    }
    int q, t, u, x, k, s;
    cin >> q;
    vector<bit_trie> T(N);
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> u;
            if (!vis[u])
            {
                vis[u] = true;
                for (int dv : divs[u])
                    T[dv].insert(u);
            }
        }
        else
        {
            cin >> x >> k >> s;
            if (x % k != 0 || s <= x || T[k].t[0].mn > s - x)
                cout << "-1\n";
            else
                cout << (T[k].max_xor_query(x, s - x) ^ x) << "\n";
        }
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