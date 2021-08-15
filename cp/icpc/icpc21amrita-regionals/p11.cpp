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

const ll inf = 1e9 + 5;
ll solve()
{
    int n;
    ll q, res = 0, sum = -inf;
    cin >> n >> q;
    vector<ll> u(n), t(n), l(n), r(n);
    vector<int> ord(n);
    for (int i = 0; i < n; i++)
        cin >> u[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n; i++)
    {
        sum = max(sum + u[i], u[i]);
        l[i] = sum;
    }
    sum = -inf;
    for (int i = n - 1; i >= 0; i--)
    {
        sum = max(sum + u[i], u[i]);
        r[i] = sum;
    }
    for (int i = 0; i < n; i++)
        res = max(res, l[i] + r[i] - u[i] + max(0ll, q * t[i]));
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