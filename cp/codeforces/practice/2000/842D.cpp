#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Bit Trie
const int N = 3e5 + 5, LGN = 18;
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

int calc(int v, int bit)
{
    if (bit == -1)
        return cnt[v];
    if (t[v][0] > 0)
        cnt[v] += calc(t[v][0], bit - 1);
    if (t[v][1] > 0)
        cnt[v] += calc(t[v][1], bit - 1);
    return cnt[v];
}

int mex(vector<vector<int>> &flip, int v, int bit)
{
    if (bit == -1)
        return 0;
    int mx = 1 << bit;
    vector<int> seq = {flip[bit][0], flip[bit][1]};
    for (int j = 0; j < 2; j++)
    {
        if (t[v][seq[j]] == 0)
            return (j << bit);
        if (cnt[t[v][seq[j]]] < mx)
            return (j << bit) | mex(flip, t[v][seq[j]], bit - 1);
    }
    return 0;
}

void solve()
{
    int n, q, x;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    memset(t, 0, sizeof(t));
    memset(cnt, 0, sizeof(cnt));
    for (int a : arr)
        insert(a, 1, LGN);
    calc(1, LGN);
    vector<vector<int>> flip(LGN + 1, vector<int>(2));
    for (int i = LGN; i >= 0; i--)
        flip[i][1] = 1;
    while (q-- > 0)
    {
        cin >> x;
        for (int i = x, j = 0; i > 0; i >>= 1, j++)
            if (i & 1)
                swap(flip[j][0], flip[j][1]);
        cout << mex(flip, 1, LGN) << "\n";
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