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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (k >= n)
        return n;
    vector<int> diff;
    for (int i = 1; i < n; i++)
        diff.pb(arr[i] - arr[i - 1]-1);
    sort(diff.rbegin(), diff.rend());
    int res = arr[n - 1] - arr[0] + 1;
    for (int i = 0; i < k - 1; i++)
        res -= diff[i];
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