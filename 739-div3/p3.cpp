#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll k;
    cin >> k;
    ll cur = 1, sum = 0, i = 0;
    while (sum < k)
    {
        i++;
        sum += cur;
        cur += 2;
    }
    cur -= 2;
    sum -= cur;
    k -= sum;
    if (k <= cur / 2)
        cout << k << " " << i << "\n";
    else if (k > cur - cur / 2)
        cout << i << " " << cur - k + 1 << "\n";
    else
        cout << i << " " << i << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}