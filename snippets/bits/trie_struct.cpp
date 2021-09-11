#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct bit_trie
{
    // set LGN to 60 for long long
    static constexpr int LGN = 30;
    static constexpr int ROOT = 0;
    static constexpr int MX = 1e9;
    struct Node
    {
        array<int, 2> ch{-1, -1};
        int cnt = 0;
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
            return;
        }
        int child = (x >> bit) & 1;
        if (t[v].ch[child] == -1)
        {
            t[v].ch[child] = ++sz;
            t.pb(Node());
        }
        insert(x, t[v].ch[child], bit - 1);
        // keep running sum
        t[v].cnt++;
    }

    // max xor with x
    // answer is (x^ans)
    int max_xor_query(int x, int v = ROOT, int bit = LGN)
    {
        if (bit == -1)
            return 0;
        int child = (x >> bit) & 1;
        if (t[v].ch[child ^ 1] != -1)
            return (1 << bit) | max_xor_query(x, t[v].ch[child ^ 1], bit - 1);
        return max_xor_query(x, t[v].ch[child], bit - 1);
    }

    bool remove(int x, int v = ROOT, int bit = LGN)
    {
        if (bit == -1)
        {
            if (t[v].cnt > 0)
                t[v].cnt--;
            return t[v].cnt == 0;
        }
        int child = (x >> bit) & 1;
        if (t[v].ch[child] > 0)
        {
            if (remove(x, t[v].ch[child], bit - 1))
                t[v].ch[child] = -1;
            t[v].cnt--;
        }
        return t[v].cnt == 0;
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
    bit_trie T;
    T.insert(1);
    T.remove(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}