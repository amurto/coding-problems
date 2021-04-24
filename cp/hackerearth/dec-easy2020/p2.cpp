#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Bit Trie
const int N = 1e5 + 5, LGN = 60;
int t[N * LGN][2], cnt[N * LGN], mask = 1;

void insert(ll x, int v, int bit)
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
    cnt[v]++;
}

// kth minimum
ll query(ll x, int k, int v, int bit)
{
    if (bit == -1)
        return 0ll;
    int child = (x >> bit) & 1;
    if (t[v][child] > 0 && cnt[t[v][child]] >= k)
        return query(x, k, t[v][child], bit - 1);
    return (1ll << bit) | query(x, k - cnt[t[v][child]], t[v][child ^ 1], bit - 1);
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
        int t, k;
        ll x;
        cin >> t >> x;
        if (t == 1)
            insert(x, 1, LGN);
        else
        {
            cin >> k;
            cout << query(x, k, 1, LGN) << "\n";
        }
        cout << "\n";
    }
    return 0;
}