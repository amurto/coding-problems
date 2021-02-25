#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    ll x, num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        num ^= x;
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}