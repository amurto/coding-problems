#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int LGN = 18;

class bus
{
public:
    int a, b, s, t, id;
    bus() {}
    bus(int a, int b, int s, int t, int id) : a(a), b(b), s(s), t(t), id(id) {}
    void display()
    {
        cout << a << " " << b << "\n";
    }
};

int bs(vector<bus> &arr, vector<vector<int>> &g, int v, int t)
{
    if (g[v].empty() || t >= arr[g[v].back()].s)
        return -1;
    int sz = g[v].size();
    int low = 0, high = sz - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[g[v][mid]].s > t)
            high = mid;
        else
            low = mid + 1;
    }
    return g[v][low];
}

int k_ancestor(vector<vector<int>> &nxt, int u, int k)
{
    for (int i = LGN; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            u = nxt[u][i];
            k -= (1 << i);
        }
    }
    return u;
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<bus> arr;
    vector<vector<int>> g(n + 1), nxt(m, vector<int>(LGN));
    for (int i = 0; i < m; i++)
    {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        arr.pb(bus(a, b, s, t, i));
        g[a].pb(i);
    }
    auto cmp = [&](int &i1, int &i2)
    {
        return arr[i1].s < arr[i2].s;
    };
    for (int i = 1; i <= n; i++)
        if (!g[i].empty())
            sort(g[i].begin(), g[i].end(), cmp);
    for (int i = 0; i < m; i++)
    {
        nxt[i][0] = bs(arr, g, arr[i].b, arr[i].t-1);
        if (nxt[i][0] == -1)
            nxt[i][0] = i;
    }
    for (int j = 1; j < LGN; j++)
        for (int i = 0; i < m; i++)
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    for (int i = 0; i < q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int id = bs(arr, g, y, x - 1);
        if (id == -1)
            cout << y << "\n";
        else
        {
            if (z <= arr[id].s)
                cout << y << "\n";
            else if (z <= arr[id].t)
                arr[id].display();
            else if (z > arr[nxt[id][LGN - 1]].t)
                cout << arr[nxt[id][LGN - 1]].b << "\n";
            else
            {
                int low = 0, high = m, res = nxt[id][LGN - 1];
                while (low <= high)
                {
                    int mid = low + (high - low) / 2;
                    int k = k_ancestor(nxt, id, mid);
                    if (arr[k].t >= z)
                    {
                        res = k;
                        high = mid - 1;
                    }
                    else
                        low = mid + 1;
                }
                if (z <= arr[res].s)
                    cout << arr[res].a << "\n";
                else
                    arr[res].display();
            }
        }
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