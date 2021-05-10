// https://codeforces.com/contest/1416/problem/B
// Make Them Equal

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<pair<int, int>, int> piii;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += 1ll * arr[i];
    }
    if (sum % n != 0)
    {
        cout << "-1\n";
        return;
    }
    int e = sum / n;
    vector<piii> op;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] % i > 0)
        {
            op.pb({{1, i}, i - arr[i] % i});
            arr[i] += i - arr[i] % i;
        }
        op.pb({{i, 1}, arr[i] / i});
    }
    for (int i = 2; i <= n; i++)
        op.pb({{1, i}, e});
    cout << op.size() << "\n";
    for (piii o : op)
        cout << o.first.first << " " << o.first.second << " " << o.second << "\n";
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