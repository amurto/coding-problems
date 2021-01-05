#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll freq(ll val, ll x)
{
    int cnt = 0;
    while (val % x == 0)
    {
        cnt++;
        val /= x;
    }
    return cnt;
}
ll solve()
{
    int n;
    ll x, sum = 0;
    cin >> n >> x;
    vector<ll> arr(n), f(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        f[i] = freq(arr[i], x);
    }
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (f[i] < f[idx])
            idx = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < idx)
            sum += (arr[i] * (f[idx] + 1));
        else
            sum += (arr[i] * f[idx]);
    }
    return sum;
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