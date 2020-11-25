#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), pre(n), suf(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    pre[0] = arr[0];
    for (int i = 1; i <= n; i++)
        pre[i] = max(pre[i - 1], arr[i]);
    suf[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], arr[i]);
    int L = 0, R = n - 1;
    multiset<int> MIN;
    for (int i = L + 1; i < R; i++)
        MIN.insert(arr[i]);
    while (L < R - 1 && pre[L] != *MIN.begin() && pre[L] != suf[R])
    {
        if (pre[L] < suf[R]) {
            L++;
            MIN.erase(arr[L]);
        } else if (pre[L] > suf[R]) {
            R--;
            MIN.erase(arr[R]);
        } else {
            
        }
    }
    if (L >= R - 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << L + 1 << " " << R - L << n - R << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}