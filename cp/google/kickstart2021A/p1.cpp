#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k, g = 0;
    string str;
    cin >> n >> k >> str;
    for (int i = 0; i < n / 2; i++)
        g += (str[i] != str[n - 1 - i]);
    return abs(k - g);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}