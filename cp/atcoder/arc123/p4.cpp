#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll calc(vector<ll> &a, ll v, int n)
{
    vector<ll> b(n), c(n);
    b[0] = v;
    c[0] = a[0] - b[0];
    for (int i = 1; i < n; i++)
    {
        b[i] = b[i - 1];
        b[i] += max(0ll, a[i] - a[i - 1]);
        c[i] = a[i] - b[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += abs(b[i]) + abs(c[i]);
    return sum;
}

ll solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll low = -1e13, high = 1e13, sum = LLONG_MAX;
    while (high - low > 2)
    {
        ll m1 = low + (high - low) / 3;
        ll m2 = high - (high - low) / 3;
        ll f1 = calc(a, m1, n);
        ll f2 = calc(a, m2, n);
        sum = min(sum, min(f1, f2));
        if (f1 < f2)
            high = m2;
        else
            low = m1;
    }
    for (ll i = low; i <= high; i++)
        sum = min(sum, calc(a, i, n));
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}