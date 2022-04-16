#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
vector<int> nums = {1, 2, 3, 10, 11, 12};
struct dsu
{
    int n, t = 0;
    vector<int> parent, cap;
    dsu() {}
    dsu(int l)
    {
        n = l;
        parent.resize(n + 1);
        cap.resize(n + 1);
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
    bool has_edge(int x, int y)
    {
        return root(x) == root(y);
    }
    bool merge_nodes(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return false;
        // by size (capacity)
        if (cap[rx] < cap[ry])
            swap(rx, ry);
        cap[rx] += cap[ry];
        parent[ry] = parent[rx];
        t--;
        return true;
    }
};

struct node
{
    int c = 0, id = -1; // identity
    vector<vector<int>> grid = {{0, 0, 0}, {0, 0, 0}};
    dsu mat;
    node() {}
    node(vector<int> gd)
    {
        mat = dsu(12);
        id = 0;
        grid[0] = grid[1] = gd;
        mat.t = grid[0][0] + grid[0][1] + grid[0][2] + grid[1][0] + grid[1][1] + grid[1][2];
        for (int i = 0; i < 3; i++)
            if (grid[0][i] == 1)
                mat.merge_nodes(i + 1, i + 4);
        if (grid[0][0] + grid[0][1] == 2)
        {
            int x = 1, y = 2;
            mat.merge_nodes(x, y);
            mat.merge_nodes(x + 3, y);
            mat.merge_nodes(x, y + 3);
            mat.merge_nodes(x + 3, y + 3);
        }
        if (grid[0][1] + grid[0][2] == 2)
        {
            int x = 2, y = 3;
            mat.merge_nodes(x, y);
            mat.merge_nodes(x + 3, y);
            mat.merge_nodes(x, y + 3);
            mat.merge_nodes(x + 3, y + 3);
        }
        if (grid[0][0] + grid[0][1] + grid[0][2] == 3)
        {
            int x = 1, y = 3;
            mat.merge_nodes(x, y);
            mat.merge_nodes(x + 3, y);
            mat.merge_nodes(x, y + 3);
            mat.merge_nodes(x + 3, y + 3);
        }
        c = mat.t;
    }
    void merge(node &l, node &r)
    {
        id = 0;
        if (l.id == -1)
        {
            c = r.c;
            mat = r.mat;
            grid = r.grid;
        }
        else if (r.id == -1)
        {
            c = l.c;
            mat = l.mat;
            grid = l.grid;
        }
        else
        {
            c = l.c + r.c;
            dsu ds(12);
            for (int t = 0; t < 2; t++)
            {
                for (int i = 0; i < 3; i++)
                {
                    ds.t += l.grid[t][i];
                    ds.t += r.grid[t][i];
                }
            }
            for (int i = 0; i < 6; i++)
                for (int j = i + 1; j < 6; j++)
                    if (l.mat.has_edge(i + 1, j + 1))
                        ds.merge_nodes(i + 1, j + 1);
            for (int i = 0; i < 6; i++)
                for (int j = i + 1; j < 6; j++)
                    if (r.mat.has_edge(i + 1, j + 1))
                        ds.merge_nodes(i + 7, j + 7);
            int tmp = ds.t;
            for (int i = 0; i < 3; i++)
                if (l.grid[1][i] + r.grid[0][i] == 2)
                    ds.merge_nodes(i + 4, i + 7);
            c -= (tmp - ds.t);
            grid[0] = l.grid[0];
            grid[1] = r.grid[1];
            mat = dsu(12);
            mat.t = l.grid[0][0] + l.grid[0][1] + l.grid[0][2] + r.grid[1][0] + r.grid[1][1] + r.grid[1][2];

            for (int i = 0; i < 6; i++)
                for (int j = i + 1; j < 6; j++)
                    if (ds.has_edge(nums[i], nums[j]))
                        mat.merge_nodes(i + 1, j + 1);
        }
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
    segtree() = default;

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            vector<int> tmp(3);
            for (int i = 0; i < 3; i++)
                tmp[i] = arr[i][tl] - '0';
            t[v] = node(tmp);
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
    int n, q;
    cin >> n;
    vector<string> grid(3);
    for (int i = 0; i < 3; i++)
        cin >> grid[i];
    cin >> q;
    segtree<node> s(n);
    s.build(grid);
    for (int i = 0; i < q; i++)
    {
        int l, r, res = 0;
        cin >> l >> r;
        l--;
        r--;
        cout << s.query(l, r).c << "\n";
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