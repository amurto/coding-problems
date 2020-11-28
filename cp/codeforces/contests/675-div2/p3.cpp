#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll MOD = 1e9 + 7;

ll add(ll x, ll y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int n = str.length();
    ll arr[n], POW[n], SP[n], ans = 0, cur=0;

    // Break the number into array
    for (int i = 0; i < n; i++) 
        arr[i] = str[i] - 48;

    // Compute Powers of 10
    // Sum of Powers is all 1s
    // POW[3] = 1000
    // SP[3] = 1111
    POW[0] = 1;
    SP[0] = 1;
    for (int i = 1; i < n; i++) {
        POW[i] = mul(POW[i - 1], 10);
        SP[i] = add(POW[i], SP[i-1]);
    }

    // Compute prices from the left
    // Substring is removed from the right
    for (int i = 0; i < n-1; i++) {
        cur = add(mul(cur, 10), arr[i]);
        ans = add(ans, mul(cur, SP[n-2-i]));
    }

    // Compute Prices from the right
    // Substring is removed from left
    cur = 0;
    for (int i = n - 1; i > 0; i--) {
        cur = add(mul(arr[i], POW[n-1-i]), cur);
        ans = add(ans, mul(cur, i));
    }

    cout << ans << "\n";
    return 0;
}