#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, sum = 0;
    cin >> n;
    for (ll i = 1; i <= 1e6; i++)
    {
        sum += i;
        if (sum >= n)
            return i;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}