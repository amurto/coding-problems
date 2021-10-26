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

void solve()
{
    int n, c, res = 0;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int p = c & 1;
    int id = lower_bound(arr.begin(), arr.end(), c) - arr.begin();
    int l = id - 1, r = id;
    while (l >= 0 && (arr[l] & 1) != p)
    {
        res++;
        l--;
    }
    while (r < n && (arr[r] & 1) != p)
    {
        res++;
        r++;
    }
    int w = (res == n) ? 1 : -1;
    cout << res << " " << w << "\n";
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