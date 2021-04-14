#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, m;

    cin >> n >> m;
    vector<string> arr(n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll res = m;
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (j < m && arr[i - 1][j] == arr[i][j])
            j++;
        res += 1ll * (m - j);
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