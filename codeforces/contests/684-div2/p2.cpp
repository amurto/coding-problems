#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, k, m;
    cin >> n >> k;
    m = n * k;
    ll res = 0;
    vector<ll> arr(m);
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    if (n==1) {
        ll sum=0;
        for (ll v: arr)
            sum+=v;
        return sum;
    }
    int mid = 0, f = 0, b = n / 2 + 1;
    f = n - b;
    for (int i = 0, j = m - 1; i < j; i += f, j -= b)
    {
        res += arr[j - b + 1];
    }
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
    {
        cout << solve() << "\n";
    }
    return 0;
}