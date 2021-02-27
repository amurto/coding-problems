#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

map<ll, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, cnt = 0;
    cin >> n;
    for (ll i = 2; i * i <= n; i++)
    {
        for (ll j = i * i; j <= n && !mp[j]; j *= i)
        {
            mp[j] = 1;
            cnt++;
        }
    }
    cout << n - cnt << "\n";
    return 0;
}