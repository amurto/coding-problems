#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e18 + 5;

// check if x*y > n
bool is_overflow(ll x, ll y, ll n)
{
    if (x == 0 || y == 0)
        return false;
    return x > (n / y);
}

// check if x*y >= n
bool is_overflow(ll x, ll y, ll n)
{
    if (x == 0 || y == 0)
        return n == 0;
    return x > ((n - 1) / y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}