#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ll n, k, s;
        cin >> n >> k >> s;
        cout << "Case #" << i << ": " << min(n + k, k - s + n - s + k) << "\n";
    }
    return 0;
}