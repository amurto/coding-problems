#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, v, res = 0;
    cin >> n;
    vector<int> f(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        f[v]++;
        res = max(res, f[v]);
    }
    return res;
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