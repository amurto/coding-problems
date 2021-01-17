// https://codeforces.com/contest/740/problem/C
// Alyona and mex

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, l, r, mx = 1e5;
    cin >> n >> m;
    vector<int> arr(n);
    while (m-- > 0)
    {
        cin >> l >> r;
        mx = min(mx, r - l + 1);
    }
    cout << mx << "\n";
    for (int i = 0; i < n; i++)
        cout << i % mx << " ";
    return 0;
}