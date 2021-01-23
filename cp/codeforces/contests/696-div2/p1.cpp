#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<int> d(n), res(n);
    d[0] = (str[0] == '1') ? 2 : 1;
    res[0] = d[0] - (str[0] - '0');
    for (int i = 1; i < n; i++)
    {
        int p = str[i] - '0', cur = (d[i - 1] == 2) ? 1 : 2;
        if (cur - p > 1)
            d[i] = d[i - 1] ^ 1;
        else
            d[i] = cur;
        res[i] = d[i] - p;
    }
    for (int r : res)
        cout << r;
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