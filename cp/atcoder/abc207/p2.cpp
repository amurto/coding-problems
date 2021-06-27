#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e9 + 1;
int solve()
{
    ll a, b, c, d, op = inf;
    cin >> a >> b >> c >> d;
    ll low = 0, high = inf;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll cyan = a + b * mid;
        ll red = c * mid;
        if (red * d >= cyan)
        {
            op = min(op, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return (op == inf) ? -1 : op;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}