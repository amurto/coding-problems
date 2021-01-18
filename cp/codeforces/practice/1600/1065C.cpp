// https://codeforces.com/contest/1065/problem/C
// Make It Equal

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 2;
vector<int> f(N);

int solve()
{
    int n, k, mn = N, mx = 0, cur = 0, res = 1;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        f[1]++;
        f[arr[i] + 1]--;
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    if (mn == mx)
        return 0;
    for (int i = 1; i <= mx; i++)
        f[i] += f[i - 1];
    for (int i = mx; i > mn; i--)
    {
        if (cur + f[i] > k)
        {
            res++;
            cur = f[i];
        }
        else
            cur += f[i];
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