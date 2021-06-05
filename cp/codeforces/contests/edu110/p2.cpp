#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, v;
    cin >> n;
    vector<int> arr, odd;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        if (v & 1)
            odd.pb(v);
        else
            arr.pb(v);
    }
    sort(odd.rbegin(), odd.rend());
    for (int o : odd)
        arr.pb(o);
    int cnt = 0;
    for (int j = 1; j < n; j++)
        for (int i = 0; i < j; i++)
            cnt += (__gcd(arr[i], 2 * arr[j]) > 1);
    return cnt;
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