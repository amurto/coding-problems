#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll op(vector<ll> &arr, ll target, int itr)
{
    ll m = 0;
    for (int i = itr; i < arr.size(); i++)
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
    ll d = -1, idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(arr[i] - arr[i - 1]) > d)
        {
            d = abs(arr[i] - arr[i]);
            idx = i;
        }
    }
    ll m = op(arr, arr[1], 1);
    ll temp = arr[idx];
    arr[idx] = arr[idx - 1];
    m = min(m, op(arr, arr[0], 1));
    arr[idx] = temp;
    temp = arr[idx - 1];
    arr[idx - 1] = arr[idx];
    m = min(m, op(arr, arr[0], 1));
    return m;
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