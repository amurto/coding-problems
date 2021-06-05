#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, pair<int, int>> piii;
#define pb push_back

const int N = 2e5 + 5;
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

bool merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (rx == ry)
        return false;

    // by size (capacity)
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return true;
}

ll solve()
{
    int n, r, c;
    ll res = 0;
    cin >> n >> r >> c;
    init(r + c);
    vector<pair<pair<int, int>, ll>> arr(n);
    vector<piii> edges;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n;)
    {
        int x = arr[i].first.first, y = arr[i].first.second, itr = i;
        vector<ll> vals;
        while (itr < n && arr[itr].first.first == x && arr[itr].first.second == y)
        {
            vals.pb(arr[itr].second);
            itr++;
        }
        sort(vals.rbegin(), vals.rend());
        ll sum = 0;
        for (ll v : vals)
            sum += v;
        // sum = vals[0];
        // if (vals.size() > 1)
        //     sum += vals[1];
        i = itr;
        edges.pb({sum, {x, r + y}});
    }
    sort(edges.rbegin(), edges.rend());
    for (piii e : edges)
        if (merge(e.second.first, e.second.second))
            res += e.first;
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