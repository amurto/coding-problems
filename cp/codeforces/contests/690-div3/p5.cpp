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
    int L = 0, R = 2;
    ll res = 0;
    while (R < n)
    {
        if (R - L == 1)
            R++;
        else if (arr[R] - arr[L] > 2)
            L++;
        else
        {
            res += ((R - L) * 1ll * (R - L - 1)/2);
            R++;
        }
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