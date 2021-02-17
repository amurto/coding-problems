// https://codeforces.com/contest/447/problem/C
// DZY Loves Sequences

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n), up(n, 1), down(n, 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            up[i] += up[i - 1];
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] < arr[i + 1])
            down[i] += down[i + 1];
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, min(n, up[i] + down[i]));
    for (int i = 2; i < n; i++)
        if (arr[i] - arr[i - 2] > 1)
            res = max(res, up[i - 2] + 1 + down[i]);
    cout << res << "\n";
    return 0;
}