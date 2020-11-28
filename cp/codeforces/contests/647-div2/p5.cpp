// tbd 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 1e9 + 7;

// Binary Exponentiation O(logn)
// n^m mod p
// p is large prime number
ll power(ll n, ll m)
{
    ll res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % MOD;
        n = (n * 1ll * n) % MOD;
        m /= 2;
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
        ll n, p;
        cin >> n >> p;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (p == 1)
        {
            cout << (n & 1) << "\n";
            continue;
        }
        sort(arr.begin(), arr.end());
        ll sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (sum == 0)
                sum = (sum + power(p, arr[i])) % MOD;
            else
                sum = (sum - power(p, arr[i]) + 2 * MOD) % MOD;
        }
        cout << sum << "\n";
    }
    return 0;
}