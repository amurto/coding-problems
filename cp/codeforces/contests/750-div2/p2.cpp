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
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    array<ll, 2> cnt{0, 0};
    for (int i = 0; i < n; i++)
        if (arr[i] <= 1)
            cnt[arr[i]]++;
    if (cnt[1] == 0)
        return 0;
    ll f = 1ll << cnt[0];
    return f * cnt[1];
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