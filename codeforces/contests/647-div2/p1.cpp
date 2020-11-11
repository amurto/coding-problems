#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve(ll a, ll b)
{
    if (a == b)
        return 0;
    if (a < b)
        swap(a, b);
    if (a % b > 0)
        return -1;
    ll req = a / b, op = 0;
    ll div[3] = {8, 4, 2};
    for (int d : div)
    {
        while (req%d == 0) {
            op++;
            req/=d;
        }
    }
    if (req > 1)
        return -1;
    return op;
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
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}