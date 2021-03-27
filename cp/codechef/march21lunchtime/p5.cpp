#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353, N = 1e3 + 5;

class interval
{
public:
    int l, r, id;
    interval() {}
    interval(int l, int r, int id) : l(l), r(r), id(id) {}
    bool operator<(const interval &j) const
    {
        if (l == j.l)
            return (r < j.r);
        return (l < j.l);
    }
};

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int parent[N], cap[N];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        cap[i] = 1;
    }
}

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

void merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (rx == ry)
        return;
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
}

int solve()
{
    int c, n, m, x, l, r, u = 0, res = 1;
    cin >> c >> n >> m;
    init(c);
    vector<interval> arr;
    for (int i = 1; i <= c; i++)
    {
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> l >> r;
            arr.pb(interval(l, r, i));
        }
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size();)
    {
        int cl = arr[i].l, cr = arr[i].r, k = arr[i].id;
        int j = i + 1;
        while (j < arr.size() && arr[j].l <= cr)
        {
            cr = max(cr, arr[j].r);
            if (k != arr[j].id)
                merge(k, arr[j].id);
            j++;
        }
        u += cr - cl + 1;
        i = j;
    }
    vector<bool> vis(c + 1);
    for (int i = 1; i <= c; i++)
    {
        int rt = root(i);
        if (vis[rt])
            continue;
        vis[rt] = true;
        res = mul(res, m);
    }
    res = mul(res, power(m, n - u, MOD));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}