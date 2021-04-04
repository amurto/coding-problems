#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n), c(n);
    vector<int> o(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i];
        sum += c[i];
    }
    auto cmp = [&](int &i1, int &i2) {
        return a[i1] < a[i2];
    };
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), cmp);
    int last = 0;
    ll mx = a[o[0]] + c[o[0]];
    for (int i = 1; i < n - 1; i++)
    {
        if (a[o[i]] + c[o[i]] > mx)
        {
            sum += max(0ll, a[o[i]] - a[o[last]] - c[o[last]]);
            mx = a[o[i]] + c[o[i]];
            last = i;
        }
    }
    sum += max(0ll, a[o[n - 1]] - a[o[last]] - c[o[last]]);
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