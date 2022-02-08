#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n;
    ll x, y, cnt = 0;
    cin >> n >> x >> y;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt += (arr[i] & 1);
    }
    ll a = (x & 1), b = ((x + 3) & 1), p = (y & 1);
    a += cnt;
    b += cnt;
    a %= 2;
    b %= 2;
    if (a == p)
        return "Alice";
    return "Bob";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}