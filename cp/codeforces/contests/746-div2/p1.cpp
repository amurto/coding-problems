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
    int n, h, res = 0;
    cin >> n >> h;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    int mx1 = arr[0], mx2 = arr[1];
    res += h / (mx1 + mx2);
    res *= 2;
    h %= (mx1 + mx2);
    if (h > 0)
    {
        if (h <= mx1)
            res++;
        else
            res += 2;
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