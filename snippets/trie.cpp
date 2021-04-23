#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Bit Trie
const int N = 2e5 + 5, LGN = 30;
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

bool remove(int x, int v, int bit)
{
    if (bit == -1)
    {
        if (cnt[v] > 0)
            cnt[v]--;
        return cnt[v] == 0;
    }
    int child = (x >> bit) & 1;
    if (t[v][child] > 0)
    {
        if (remove(x, t[v][child], bit - 1))
            t[v][child] = 0;
    }
    return !(t[v][0] | t[v][1]);
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
    int q, x;
    cin >> q;
    char ch;
    insert(0, 1, LGN);
    while (q-- > 0)
    {
        cin >> ch >> x;
        if (ch == '+')
            insert(x, 1, LGN);
        else if (ch == '-')
            remove(x, 1, LGN);
        else
            cout << query(x, 1, LGN) << "\n";
    }
    return 0;
}