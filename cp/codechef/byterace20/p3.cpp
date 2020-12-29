#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q, l, r;
    cin >> n >> q;
    vector<ll> st(n + 1), fn(n + 1), dec(n + 1), des(n + 1);
    while (q-- > 0)
    {
        cin >> l >> r;
        l--;
        r--;
        st[l]++;
        fn[r]++;
        dec[r] += r - l + 1;
    }
    ll inc = 0, pre = 0;
    for (int i = 0; i < n; i++)
    {
        inc += st[i];
        pre += inc;
        des[i] += pre;
        inc -= fn[i];
        pre -= dec[i];
    }
    for (int i = 0; i < n; i++)
        cout << des[i] << " ";
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