#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll ugliness(vector<ll> &arr, int n)
{
    ll sum = arr[0] + arr[n - 1];
    for (int i = 1; i < n; i++)
        sum += abs(arr[i] - arr[i - 1]);
    return sum;
}

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
        return arr[0];
    if (arr[0] > arr[1])
    {
        res += arr[0] - arr[1];
        arr[0] = arr[1];
    }
    if (arr[n - 1] > arr[n - 2])
    {
        res += arr[n - 1] - arr[n - 2];
        arr[n - 1] = arr[n - 2];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            res += arr[i] - max(arr[i - 1], arr[i + 1]);
            arr[i] = max(arr[i - 1], arr[i + 1]);
        }
    }
    return res + ugliness(arr, n);
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