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

ll solve()
{
    int n, k;
    ll res = 0;
    cin >> n >> k;
    vector<ll> A(n), B(n), diff(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];
    ll cur_sum = 0, cur_diff = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        A[i] += cur_sum;
        if (A[i] < B[i])
        {
            ll t = min(i + 1, k);
            ll req = (B[i] - A[i] + t - 1) / t;
            A[i] += req * t;
            cur_sum += req * t;
            cur_diff += req;
            res += req;
            diff[i - t + 1] -= req;
        }
        cur_sum -= cur_diff;
        cur_diff += diff[i];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}