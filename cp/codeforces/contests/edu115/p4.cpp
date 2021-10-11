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

ll nc3(ll n)
{
    return (n * (n - 1) * (n - 2)) / 6;
}

ll solve()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    vector<ll> cntA(n + 1), cntB(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i];
        cntA[A[i]]++;
        cntB[B[i]]++;
    }
    ll res = nc3(n);
    for (int i = 0; i < n; i++)
        res -= (cntA[A[i]] - 1) * (cntB[B[i]] - 1);
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