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
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> A(n), C(n);
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
        sum += C[i];
    }
    if (sum > 0)
    {
        for (int i = 0; i < n; i++)
            A[i] = 1;
        ll pre = 0;
        vector<ll> diff(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre += diff[i];
            C[i] += pre;
            if (i + C[i] < n)
                A[i + C[i]] = 0;
            pre -= C[i];
            if (i + C[i] < n)
                diff[i + C[i]] += C[i];
            d(A);
        }
    }

    for (int a : A)
        cout << a << " ";
    cout << "\n";
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