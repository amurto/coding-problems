#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    ll x, sum = 0, mx = 0;
    cin >> n >> m;
    vector<ll> arr(n), st(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        mx = max(mx, sum);
        st[i] = mx;
    }
    sort(st.begin(), st.end());
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        ll op = 0;
        int id = lower_bound(st.begin(), st.end(), x) - st.begin();
        if (id >= 0 && id < n)
            op = id;
        else if (sum <= 0)
            op = -1;
        else
        {
            ll d = (x - st[n - 1] + sum - 1) / sum;
            op += n * d - 1;
            x -= sum * d;
            if (x != 0)
                op += (int)(lower_bound(st.begin(), st.end(), x) - st.begin()) + 1;
        }
        cout << op << " ";
    }
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
        solve();
    return 0;
}