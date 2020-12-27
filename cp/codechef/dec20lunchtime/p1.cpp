#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, k, v, sum = 0;
        cin >> n >> k;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v;
            sum += v;
        }
        (sum % k == 0) ? cout << "0\n" : cout << "1\n";
    }
    return 0;
}