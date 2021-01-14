// https://codeforces.com/contest/518/problem/C
// Anya and Smartphone

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 1;
int R[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, app, idx;
    cin >> n >> m >> k;
    ll res = 0;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        R[arr[i]] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> app;
        idx = R[app];
        if (idx == 1)
        {
            res++;
            continue;
        }
        res += (idx + k - 1) / k;
        swap(arr[idx - 1], arr[idx]);
        R[arr[idx]] = idx;
        R[app]--;
    }
    cout << res << "\n";
    return 0;
}