#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n), a;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0, j = 0; i < n; j++, i += k)
    {
        int r = i + k - 1;
        if (j & 1)
            a.pb(b[r]);
        else
            a.pb(b[i]);
    }
    int last = a.size() - 1;
    vector<int> tmp;
    for (int i = n - k; i < n; i++)
        tmp.pb(b[i]);
    if (last & 1)
        reverse(tmp.begin(), tmp.end());
    for (int i = 1; i < tmp.size(); i++)
        a.pb(tmp[i]);
    for (int e : a)
        cout << e << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}