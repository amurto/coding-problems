#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        if ((x + k * i) % n == y)
            return "YES";
    }
    return "NO";
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
        cout << solve() << "\n";
    }
    return 0;
}