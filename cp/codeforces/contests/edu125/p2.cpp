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

ll solve()
{
    int n;
    ll b, x, y, res = 0;
    cin >> n >> b >> x >> y;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr[i - 1];
        if (arr[i] + x <= b)
            arr[i] += x;
        else
            arr[i] -= y;
        res += arr[i];
    }
    return res;
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