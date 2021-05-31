#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<piii> op;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i += 2)
    {
        int l = i - 1, r = i;
        op.pb({1, {l + 1, r + 1}});
        arr[l] += arr[r];
        op.pb({2, {l + 1, r + 1}});
        arr[r] -= arr[l];
        op.pb({2, {l + 1, r + 1}});
        arr[r] -= arr[l];
        op.pb({1, {l + 1, r + 1}});
        arr[l] += arr[r];
        op.pb({2, {l + 1, r + 1}});
        arr[r] -= arr[l];
        op.pb({2, {l + 1, r + 1}});
        arr[r] -= arr[l];
    }
    cout << op.size() << "\n";
    for (piii p : op)
        cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
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