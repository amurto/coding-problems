#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll op(vector<ll> &arr)
{
    ll m = 0;
    for (int i = 1; i < arr.size(); i++)
        m += abs(arr[i] - arr[i - 1]);
    return m;
}

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int itr = 1;
    while (itr < n && arr[itr] == arr[itr - 1])
        itr++;
    if (n == 2 || itr == n)
        return 0;
    ll m = op(arr), rem = max(abs(arr[1] - arr[0]), abs(arr[n - 1] - arr[n - 2]));
    for (int i = 1; i < n - 1; i++)
        rem = max(rem, abs(arr[i] - arr[i - 1]) + abs(arr[i + 1] - arr[i]) - abs(arr[i + 1] - arr[i - 1]));
    return m - rem;
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