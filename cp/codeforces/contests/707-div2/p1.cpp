#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), tm(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> tm[i];
    int last = 0;
    for (int i = 1; i < n; i++)
    {
        last += a[i] - b[i - 1] + tm[i];
        int req = (b[i] - a[i] + 1) / 2;
        last = max({last + req, b[i]});
    }
    last += a[n] - b[n - 1] + tm[n];
    return last;
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