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

const int N = 1005;
int L[N], R[N], ans[N][N];
void calc(vector<bool> &vis, int l, int r, int n)
{
    int id = 0;
    for (int i = 0; i < n; i++)
        if (L[i] == l && R[i] == r)
            id = i;
    vis[id] = true;
    if (l == r)
    {
        ans[l][r] = l;
        return;
    }
    int b1 = l - 1, b2 = r + 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (L[i] == l)
                b1 = max(b1, R[i]);
            if (R[i] == r)
                b2 = min(b2, L[i]);
        }
    }
    ans[l][r] = b1 + 1;
    if (b1 >= l)
        calc(vis, l, b1, n);
    if (b2 <= r)
        calc(vis, b2, r, n);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> L[i] >> R[i];
    vector<bool> vis(n);
    calc(vis, 1, n, n);
    for (int i = 0; i < n; i++)
        cout << L[i] << " " << R[i] << " " << ans[L[i]][R[i]] << "\n";
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