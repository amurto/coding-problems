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

const ll MX = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    arr[0] = 1;
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] * 3;
        if (arr[i] > MX)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (ll x : arr)
        cout << x << " ";
    cout << "\n";
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