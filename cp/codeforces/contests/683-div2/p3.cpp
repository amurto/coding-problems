#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    ll w, sum = 0;
    cin >> n >> w;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> idx;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > w)
            continue;
        if (arr[i] >= (w + 1) / 2 && arr[i] <= w)
        {
            cout << "1\n"
                 << i + 1 << "\n";
            return;
        }
        sum += arr[i];
        idx.pb(i + 1);
        if (sum >= (w + 1) / 2 && sum <= w)
            break;
    }
    if (sum < (w + 1) / 2)
    {
        cout << "-1\n";
        return;
    }
    cout << idx.size() << "\n";
    for (int id : idx)
        cout << id << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}