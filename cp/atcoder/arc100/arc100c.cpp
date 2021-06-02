// https://atcoder.jp/contests/arc100/tasks/arc100_c
// Or Plus Max

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    int sz = 1 << n;
    vector<int> arr(sz);
    vector<vector<int>> f(sz, vector<int>(2));
    for (int i = 0; i < sz; i++)
        cin >> arr[i];
    for (int b = 0; b < n; b++)
        for (int mask = 0; mask < sz; mask++)
        {
            if ((mask >> b) & 1)
            {
                vector<int> seq = {f[mask][0], f[mask][1], f[mask ^ (1 << b)][0], f[mask ^ (1 << b)][1], arr[mask ^ (1 << b)]};
                sort(seq.rbegin(), seq.rend());
                f[mask][0] = seq[0];
                f[mask][1] = seq[1];
            }
        }
    for (int i = 1; i < sz; i++)
    {
        vector<int> seq = {arr[i], f[i][0], f[i][1]};
        sort(seq.rbegin(), seq.rend());
        arr[i] = seq[0] + seq[1];
    }
    for (int i = 1; i < sz; i++)
        arr[i] = max(arr[i - 1], arr[i]);
    for (int i = 1; i < sz; i++)
        cout << arr[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}