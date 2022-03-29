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

void solve()
{
    int n, m;
    cin >> n >> m;
    int sz = n + m;
    vector<ll> A(n + 1), B(m + 1), C(sz + 1);
    for (int i = 0; i <= n; i++)
        cin >> A[i];
    for (int i = 0; i <= sz; i++)
        cin >> C[i];
    for (int i = sz, t = m; t >= 0; i--, t--)
    {
        ll sum = 0;
        for (int j = t + 1; j <= m; j++)
            if (j <= i && i - j <= n)
                sum += (B[j] * A[i - j]);
        B[t] = (C[i] - sum) / A[n];
    }
    for (ll v : B)
        cout << v << " ";
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