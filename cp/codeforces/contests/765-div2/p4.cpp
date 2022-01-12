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

const int N = 3e5 + 5;
int arr[N];
struct bit_trie
{
    // set LGN to 60 for long long
    static constexpr int LGN = 30;
    static constexpr int ROOT = 0;
    static constexpr int MX = 2e9;
    struct Node
    {
        array<int, 2> ch{-1, -1};
        int id = 0;
        vector<int> ids;
    };
    int sz;
    vector<Node> t;
    bit_trie()
    {
        sz = 0;
        t.assign(1, Node());
    }
    void insert(int x, int idx, int v = ROOT, int bit = LGN)
    {
        if (bit == -1)
        {
            t[v].id = idx;
            t[v].ids.pb(idx);
            return;
        }
        int child = (x >> bit) & 1;
        if (t[v].ch[child] == -1)
        {
            t[v].ch[child] = ++sz;
            t.pb(Node());
        }
        insert(x, idx, t[v].ch[child], bit - 1);
        t[v].id = idx;
    }

    int calc(int x, int k, int v = ROOT, int bit = LGN)
    {
        if (bit == -1)
            return t[v].id;
        int x_bit = ((x >> bit) & 1), cur = ((k >> bit) & 1);
        if (cur == 1)
        {
            if (t[v].ch[x_bit ^ 1] >= 0)
                return calc(x, k, t[v].ch[x_bit ^ 1], bit - 1);
            return -1;
        }
        else
        {
            if (t[v].ch[x_bit ^ 1] >= 0)
                return t[t[v].ch[x_bit ^ 1]].id;
            return calc(x, k, t[v].ch[x_bit], bit - 1);
        }
        return -1;
    }

    void get_all_ids(vector<int> &indices, int v = ROOT, int bit = LGN)
    {
        if (bit == -1)
            indices.pb(t[v].id);
        for (int j = 0; j < 2; j++)
            if (t[v].ch[j] >= 0)
                get_all_ids(indices, t[v].ch[j], bit - 1);
    }
    
    void traverse(int k, int v = ROOT, int bit = LGN)
    {
        if (bit == -1)
            return;
        if ((k >> bit) & 1)
        {
            if (t[v].ch[0] == -1 || t[v].ch[1] == -1)
                t[v].ids.pb(t[v].id);
            else
            {
                vector<int> indices;
                get_all_ids(indices, t[v].ch[0], bit - 1);
                for (int i : indices)
                {
                    int c = calc(arr[i - 1], k, t[v].ch[1], bit - 1);
                    if (c >= 0)
                    {
                        t[v].ids.pb(i);
                        t[v].ids.pb(c);
                        break;
                    }
                }
                if (t[v].ids.empty())
                    t[v].ids.pb(t[v].id);
            }
            return;
        }
        for (int j = 0; j < 2; j++)
        {
            if (t[v].ch[j] >= 0)
            {
                traverse(k, t[v].ch[j], bit - 1);
                for (int i : t[t[v].ch[j]].ids)
                    t[v].ids.pb(i);
            }
        }
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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (k == 0)
    {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << "\n";
        return;
    }
    set<int> vis;
    bit_trie tr;
    for (int i = 0; i < n; i++)
    {
        if (vis.find(arr[i]) == vis.end())
            tr.insert(arr[i], i + 1);
        vis.insert(arr[i]);
    }
    tr.traverse(k);
    int res = (int)tr.t[0].ids.size();
    if (res < 2)
    {
        cout << "-1\n";
        return;
    }
    cout << res << "\n";
    for (int id : tr.t[0].ids)
        cout << id << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}