#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q, t;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> st(51);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (st[arr[i]] == 0)
            st[arr[i]] = i;
    }
    while (q-- > 0)
    {
        cin >> t;
        cout << st[t] << " ";
        for (int i = 1; i <= 50; i++)
        {
            if (st[i] == 0 || i == t)
                continue;
            if (st[i] < st[t])
                st[i]++;
        }
        st[t] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}