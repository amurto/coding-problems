// https://codeforces.com/blog/entry/43440

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll f(ll x)
{
    return 1;
}

ll ternary_search()
{
    ll low = 0, high = 1e9, res = 1e18;
    // finding minimum
    while (high - low > 1)
    {
        ll mid = low + (high - low) / 2;
        if (f(mid) > f(mid + 1))
            low = mid;
        else
            high = mid;
    }
    // answer is low + 1
    return low + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}