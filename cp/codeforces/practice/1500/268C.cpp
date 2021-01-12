// https://codeforces.com/contest/268/problem/C
// Beautiful Sets of Points

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    cout << n + 1 << "\n";
    for (int i = 0; i <= n; i++)
        cout << i << " " << n - i << "\n";
    return 0;
}