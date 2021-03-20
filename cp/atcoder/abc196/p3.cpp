#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll dup(ll cur)
{
    int len = 0;
    ll x = cur, y = cur;
    while (x > 0)
    {
        len++;
        x /= 10;
    }
    while (len > 0)
    {
        len--;
        y *= 10;
    }
    return y + cur;
}

int solve()
{
    ll n, cur = 0;
    cin >> n;
    while (dup(cur) <= n)
        cur++;
    return cur - 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}