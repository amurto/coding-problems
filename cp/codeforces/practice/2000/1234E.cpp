// https://codeforces.com/contest/1234/problem/E
// Special Permutations

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> arr(m), diff(n + 2);
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    for (int i = 1; i < m; i++)
    {
        ll l = arr[i - 1], r = arr[i];
        if (l > r)
            swap(l, r);
        if (l != r)
        {
            int dis = r - l;
            diff[0] += dis;
            diff[l] -= dis;
            diff[r + 1] += dis;
            diff[n + 1] -= dis;
            diff[l] += r - 1;
            diff[l + 1] -= r - 1;
            diff[r] += l;
            diff[r + 1] -= l;
            diff[l + 1] += dis - 1;
            diff[r] -= dis - 1;
        }
    }
    for (int i = 1; i < n + 2; i++)
        diff[i] += diff[i - 1];
    for (int i = 1; i <= n; i++)
        cout << diff[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}