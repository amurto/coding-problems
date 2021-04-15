#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    int v = 0; // identity
    node() {}
    node(int val)
    {
        v = val;
    }
    void merge(const node &l, const node &r)
    {
        v = max(l.v, r.v);
    }
};

template <typename node>
struct segtree
{
    int len;
    vector<node> t;
    node identity_element;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        identity_element = node();
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].v = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
            return identity_element;
        if (l <= tl && tr <= r)
            return t[v];
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
};

void solve()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<int> arr(n), vis(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
            st.pop();
        if (!st.empty())
            vis[st.top()]--;
        if (i > 0)
            vis[i - 1]++;
        st.push(i);
    }
    for (int i = n - 2; i >= 0; i--)
        vis[i] += vis[i + 1];
    segtree<node> s(n);
    s.build(arr);
    while (m-- > 0)
    {
        cin >> a >> b;
        a--;
        b--;
        int l = max(a, b), r = n - 1, res = b, mn = min(arr[a], arr[b]);
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int mx = s.query(b, mid).v;
            if (mx <= mn)
            {
                res = max(res, mid);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << vis[res] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}