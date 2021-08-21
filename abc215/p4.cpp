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

const int N = 1e5 + 5;
// O(n)
vector<int> lp(N + 1), pr;
bool vis[N];
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int i = 1; i < N; i++)
        vis[i] = false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), res;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        while (arr[i] > 1)
        {
            int dv = lp[arr[i]];
            vis[dv] = true;
            while (arr[i] % dv == 0)
                arr[i] /= dv;
        }
    }
    vector<bool> g(m + 1, true);
    for (int i = 2; i <= m; i++)
        if (vis[i])
            for (int j = i; j <= m; j += i)
                g[j] = false;
    for (int i = 1; i <= m; i++)
        if (g[i])
            res.pb(i);
    cout << res.size() << "\n";
    for (int r : res)
        cout << r << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    solve();
    return 0;
}