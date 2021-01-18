// https://codeforces.com/contest/347/problem/C
// Alice and Bob

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string w[2] = {"Alice", "Bob"};
    int n, v, g = 0, mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        g = __gcd(g, v);
        mx = max(mx, v);
    }
    cout << w[((mx / g - n) % 2) ^ 1] << "\n";
    return 0;
}