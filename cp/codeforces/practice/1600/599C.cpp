// https://codeforces.com/contest/599/problem/C
// Day at the Beach

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, mx = 0, res = 0;
    cin >> n;
    vector<int> arr(n), mn(n + 1);
    mn[n] = 1e9;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; i--)
        mn[i] = min(mn[i + 1], arr[i]);
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
        if (mx <= mn[i + 1])
            res++;
    }
    cout << res << "\n";
    return 0;
}