#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    ll n, cnt = 0;
    cin >> n;
    while (n % 2 == 0)
    {
        cnt++;
        n /= 2;
    }
    if (cnt == 0)
        return "Odd";
    else if (cnt == 1)
        return "Same";
    return "Even";
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