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

const int N = 5e5 + 5;
vector<int> ids[N];
void solve()
{
    int q, n = 0;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int t, x, y;
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            ids[x].pb(n);
            n++;
        }
        else
        {
            cin >> x >> y;
            if (x != y)
            {
                int sz1 = (int)ids[x].size(), sz2 = (int)ids[y].size();
                if (sz1 > sz2)
                    swap(ids[x], ids[y]);
                for (int id : ids[x])
                    ids[y].pb(id);
                ids[x].clear();
            }
        }
    }
    vector<int> arr(n);
    for (int i = 1; i < N; i++)
        for (int id : ids[i])
            arr[id] = i;
    for (int v : arr)
        cout << v << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}