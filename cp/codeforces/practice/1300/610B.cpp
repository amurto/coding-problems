// https://codeforces.com/contest/610/problem/B
// Vika and Squares

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mn = INT_MAX;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    int fmn = 0, close = -1;
    while (fmn < n && arr[fmn] != mn)
        fmn++;
    ll res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == mn)
            close = i;
        int dis = 0;
        if (close == -1)
            dis = fmn + n - i;
        else
            dis = close - i;
        res = max(res, mn * 1ll * n + dis);
    }
    cout << res << "\n";
    return 0;
}