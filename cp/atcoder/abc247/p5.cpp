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
    int n, x, y;
    ll res = 0;
    cin >> n >> x >> y;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int pmn = -1, mn = -1, pmx = -1, mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
            pmx = i;
        if (arr[i] == x)
            mx = i;
        if (arr[i] < y)
            pmn = i;
        if (arr[i] == y)
            mn = i;
        if (mn != -1 && mx != -1 && pmn < mn && pmx < mx)
        {
            int l = max(pmn + 1, pmx + 1), r = min(mn, mx);
            if (l <= r)
                res += r - l + 1;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}