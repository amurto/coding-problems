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
    ll sum = 0, pre = 0;
    vector<ll> A(n), C(n);
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
        sum += C[i];
    }
    int ones = sum / n;
    vector<ll> diff(n);
    for (int i = n - 1; ones > 0 && i >= 0; i--)
    {
        C[i] += pre;
        pre--;
        diff[i - ones + 1]++;
        if (C[i] == i + 1)
        {
            A[i] = 1;
            ones--;
        }
        pre += diff[i];
    }
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
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