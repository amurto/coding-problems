#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n <= 2)
        return 0;
    sort(arr.begin(), arr.end());
    vector<int> diff = arr;
    for (int i = 1; i < n; i++)
        diff[i] = arr[i] - arr[i - 1];
    ll res = 0, cur = 0, sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += diff[i];
        cur += diff[i] * 1ll * i;
        res += cur;
    }
    return -res + sum;
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