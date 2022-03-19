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

const ll inf = 1e18;
ll solve()
{
    int n;
    cin >> n;
    ll res = inf;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    ll a1 = inf, a2 = inf, b1 = inf, b2 = inf;
    for (ll v : B)
    {
        a1 = min(a1, abs(A[0] - v));
        a2 = min(a2, abs(A[n - 1] - v));
    }
    for (ll v : A)
    {
        b1 = min(b1, abs(B[0] - v));
        b2 = min(b2, abs(B[n - 1] - v));
    }
    // a1-b1
    res = min(res, abs(A[0] - B[0]) + min(a2 + b2, abs(A[n - 1] - B[n - 1])));
    // a2-b2
    res = min(res, abs(A[n - 1] - B[n - 1]) + min(a1 + b1, abs(A[0] - B[0])));
    // a1-b2 and a2-b1
    res = min(res, abs(A[0] - B[n - 1]) + abs(A[n - 1] - B[0]));
    res = min(res, abs(A[0] - B[n - 1]) + a2 + b1);
    res = min(res, abs(A[n - 1] - B[0]) + a1 + b2);
    res = min(res, a1 + b1 + a2 + b2);
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