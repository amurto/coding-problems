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

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), pre_mn(n), pre_mx(n), suf_mn(n), suf_mx(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    pre_mn[0] = pre_mx[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre_mn[i] = min(pre_mn[i - 1], arr[i]);
        pre_mx[i] = max(pre_mx[i - 1], arr[i]);
    }
    suf_mn[n - 1] = suf_mx[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf_mn[i] = min(suf_mn[i + 1], arr[i]);
        suf_mx[i] = max(suf_mx[i + 1], arr[i]);
    }
    for (int i = 1; i < n; i++)
        if (pre_mn[i - 1] > suf_mx[i])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}