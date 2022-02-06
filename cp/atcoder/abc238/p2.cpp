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

int solve()
{
    int n, sum = 0, res = 0;
    cin >> n;
    vector<int> arr(n), pts;
    pts.pb(0);
    pts.pb(360);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        sum %= 360;
        pts.pb(sum);
    }
    sort(pts.begin(), pts.end());
    int sz = (int)pts.size();
    for (int i = 1; i < sz; i++)
        res = max(res, pts[i] - pts[i - 1]);
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