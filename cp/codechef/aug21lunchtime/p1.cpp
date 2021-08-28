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
    int n, k;
    cin >> n >> k;
    ll res = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
        if (arr[i] == mx && i + 1 >= k)
            res += 1ll * (n - i);
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