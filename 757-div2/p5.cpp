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

const ll MOD = 1e9 + 1;
void solve()
{
    int n;
    cin >> n;
    vector<ll> T(n), K(n);
    vector<vector<ll>> g(n);
    for (int i = 0; i < n; i++)
    {
        cin >> T[i] >> K[i];
        g[i].resize(K[i]);
        for (int j = 0; j < K[i]; j++)
            cin >> g[i][j];
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