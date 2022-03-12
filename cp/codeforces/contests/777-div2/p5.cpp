#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int LGN = 31;

int k_ancestor(vector<vector<int>> &up, int u, int k)
{
    for (int i = LGN - 1; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            u = up[i][u];
            k -= (1 << i);
        }
    }
    return u;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n + 1), p(n + 1), arr(n + 1), beg(n + 1, n + 1);
    vector<vector<int>> nxt(LGN, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
        vis[p[i]] = true;
    int unvis = 0, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            mx = max(mx, arr[i]);
            unvis++;
        }
    }
    if (unvis == 0 || mx <= n)
    {
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int cnt = (mx - n) / unvis;
    for (int i = 1; i <= n; i++)
        nxt[0][i] = p[i];
    for (int i = 1; i < LGN; i++)
        for (int j = 1; j <= n; j++)
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
    for (int i = 1; i <= n; i++)
    {
        int anc = k_ancestor(nxt, i, cnt);
        if (arr[anc] <= n)
        {
            b[i] = arr[anc];
            beg[arr[anc]] = min(beg[arr[anc]], i);
        }
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    for (int i = 1; i <= n; i++)
        if (arr[i] <= n)
            st.erase(arr[i]);
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 0)
        {
            b[i] = *st.begin();
            st.erase(st.begin());
        }
        else
        {
            if (beg[b[i]] != i)
            {
                auto it = st.upper_bound(b[i]);
                b[i] = *it;
                st.erase(it);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}