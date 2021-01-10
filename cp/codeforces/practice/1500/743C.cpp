// https://codeforces.com/contest/743/problem/C
// Vladik and fractions

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "-1\n";
        return;
    }
    cout << n << " " << n + 1 << " " << n * (n + 1) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}