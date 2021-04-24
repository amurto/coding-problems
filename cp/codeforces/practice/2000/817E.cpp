// https://codeforces.com/contest/817/problem/E
// Choosing The Commander

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Bit Trie
const int N = 1e5 + 5, LGN = 30;
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
    cnt[v]++;
    insert(x, t[v][child], bit - 1);
}

bool remove(int x, int v, int bit)
{
    if (bit == -1)
        return --cnt[v] == 0;
    int child = (x >> bit) & 1;
    if (remove(x, t[v][child], bit - 1))
        t[v][child] = 0;
    cnt[v]--;
    return !(t[v][0] | t[v][1]);
}

int query(int p, int l, int v, int bit)
{
    if (bit == -1)
        return 0;
    int cur = (p >> bit) & 1, child = (l >> bit) & 1, sum = 0;
    vector<int> seq = {0, 1};
    if (cur)
        swap(seq[0], seq[1]);
    for (int j = 0; j <= 1; j++)
    {
        int b = seq[j];
        if (child > b)
            sum += cnt[t[v][j]];
        else if (child == b && t[v][j] > 0)
            sum += query(p, l, t[v][j], bit - 1);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
    int q;
    cin >> q;
    while (q-- > 0)
    {
        int t, p, l;
        cin >> t >> p;
        if (t == 1)
            insert(p, 1, LGN);
        else if (t == 2)
            remove(p, 1, LGN);
        else
        {
            cin >> l;
            cout << query(p, l, 1, LGN) << "\n";
        }
    }
    return 0;
}